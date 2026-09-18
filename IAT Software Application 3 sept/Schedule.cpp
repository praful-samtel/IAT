// Schedule.cpp: implementation of the CSchedule class.
//
////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Schedule.h"

// Container for CSchedule objects.
std::vector<CSchedule*>  CSchedule::s_veclpSchd;
DWORD	CSchedule::m_ulTickCount=0;	
DWORD	CSchedule::m_ulSchTime=0;	

/**
 * Function name    : CSchedule::CSchedule
 * Description      : Constructor. Initialises member variables.
 **/
CSchedule::CSchedule()
{
    m_hWnd      = NULL;
    m_uMsg      = 0;
    m_wParam    = 0;
    m_lParam    = 0;
	m_ulTickCount = 0;
    m_idTimer               = 0;
    m_dwScheduleTime        = 0;
	m_ulSchTime				= 0;
    m_fnScheduledFunction   = NULL;
}


/**
 * Function name    : CSchedule::~CSchedule
 * Description      : Destructor. Removes schedule object from container.
 **/
CSchedule::~CSchedule()
{
    CSchedule::StopTimer(this->m_idTimer);
}


/**
 * Function name    : CSchedule::StartSchedule
 * Description      : Start this schedule object.
 * Return type      : BOOL              - TRUE if successful.
 **/
BOOL CSchedule::StartSchedule()
{
	m_ulTickCount = GetTickCount();
    return StartTimer(this);
}


/**
 * Function name    : CSchedule::StopSchedule
 * Description      : Stop this schedule object.
 * Return type      : BOOL              - TRUE if successful.
 **/
BOOL CSchedule::StopSchedule()
{
    return StopTimer(this->m_idTimer);
}


/**
 * Function name    : CSchedule::SetScheduleTime
 * Description      : Set the schedule time. Timer will go off on the
 *                    dwSchedule-th millisecond on the Local Time.
 *                    The schedule time can be set at any instance whether
 *                    object has already started or not.
 * Return type      : BOOL                  - TRUE if successful.
 * Argument         : DWORD dwScheduleTime  - Scheduled time.
 **/
BOOL CSchedule::SetScheduleTime(DWORD dwScheduleTime)
{
    m_dwScheduleTime = dwScheduleTime;
	m_ulSchTime = dwScheduleTime;

    if(this->m_idTimer)
    {
        StopSchedule();
        return StartSchedule();
    }

    return TRUE;
}


/**
 * Function name    : CSchedule::SetScheduleFunction
 * Description      : Set the scheduled C function to call.
 *                    For C++ methods see ScheduleProcess.
 * Return type      : VOID 
 * Argument         : VOID (*fn)()  - Pointer to function.
 **/
VOID CSchedule::SetScheduleFunction(VOID(*fn)(int),int value)
{
    m_fnScheduledFunction = fn;
	Value_ToSend = value;
}


/**
 * Function name    : CSchedule::SetPostMessage
 * Description      : Set windows message to post.
 * Return type      : VOID
 * Argument         : HWND hWnd         - Handle to destination window.
 * Argument         : UINT uMsg         - Message to post, e.g. WM_TIMER.
 * Argument         : WPARAM wParam     - 1st message parameter.
 * Argument         : LPARAM lParam     - 2nd message parameter.
 **/
VOID CSchedule::SetPostMessage(HWND hWnd, UINT uMsg,
                               WPARAM wParam, LPARAM lParam)
{
    m_hWnd      = hWnd;
    m_uMsg      = uMsg;
    m_wParam    = wParam;
    m_lParam    = lParam;
}


/**
 * Function name    : CSchedule::ScheduleProcess
 * Description      : ScheduleProcess is called when the schedule timer is
 *                    triggered. By default scheduled function is called.
 *                    Overide this method to control the schedule process.
 * Return type      : VOID 
 **/
VOID CSchedule::ScheduleProcess()
{
    if(m_fnScheduledFunction)
        m_fnScheduledFunction(Value_ToSend);
}


/**
 * Function name    : CSchedule::GlobalTimerProcess
 * Description      : Application defined callback function adhering to
 *                    Win32 API TimerProc.
 *                    This is a private static function.
 * Return type      : VOID CALLBACK 
 * Argument         : HWND hWnd         - Handle to window.
 * Argument         : UINT uMsg         - WM_TIMER message
 * Argument         : UINT_PTR idTimer  - timer identifier.
 * Argument         : DWORD dwTime      - current system time.
 **/
VOID CALLBACK CSchedule::GlobalTimerProcess(HWND hWnd, UINT uMsg,
                                            UINT_PTR idTimer, DWORD dwTime)
{
	DWORD Tick=0;
	DWORD Diff=0;	

    for(int i = 0; i < s_veclpSchd.size(); i++)
    {
        // Find pointer to schedule object
        CSchedule* lpSchd = s_veclpSchd[i];
        if(lpSchd->m_idTimer == idTimer)
        {
            // Stop the schedule object.
            CSchedule::StopTimer(idTimer);

			Tick = GetTickCount();
			Diff = Tick - m_ulTickCount;
			if(Diff < m_ulSchTime)
			{
				Sleep(m_ulSchTime - Diff);
			}

            // Call the ScheduleProcess.
            lpSchd->ScheduleProcess();

            // Post Windows Message.
            /*::PostMessage(lpSchd->m_hWnd,
                lpSchd->m_uMsg,
                lpSchd->m_wParam,
                lpSchd->m_lParam);*/

            // Restart the schedule object.
            //CSchedule::StartTimer(lpSchd);
        }
    }
}


/**
 * Function name    : CSchedule::StartTimer
 * Description      : Start a schedule object's timer.
 *                    Timer is triggered at the scheduled time by local time.
 *                    This is a private static function.
 * Return type      : BOOL              - TRUE if successful.
 * Argument         : CSchedule* lpSchd - pointer to schedule object.
 **/
BOOL CSchedule::StartTimer(CSchedule* lpSchd)
{
    // Get local time.
    SYSTEMTIME sysTime;
	::GetLocalTime(&sysTime);

    DWORD dwNow = (sysTime.wDay    * 1000 * 60 * 60 * 24) +
                  (sysTime.wHour   * 1000 * 60 * 60)      +
                  (sysTime.wMinute * 1000 * 60)           +  
                  (sysTime.wSecond * 1000)                +
                  (sysTime.wMilliseconds);

    // Calculate the next time to trigger.
    //DWORD dwElapse = lpSchd->m_dwScheduleTime - dwNow%lpSchd->m_dwScheduleTime;
	//sivagnanam
	DWORD dwElapse = lpSchd->m_dwScheduleTime;

    // Set the timer.
    lpSchd->m_idTimer = ::SetTimer(NULL, 0, dwElapse, (TIMERPROC)GlobalTimerProcess);
    if(lpSchd->m_idTimer)
    {
        // Push pointer to object into container.
        s_veclpSchd.push_back(lpSchd);
        return TRUE;
    }

    return FALSE;
}


/**
 * Function name    : CSchedule::StopTimer
 * Description      : Stop a schedule object's timer.
 * Return type      : BOOL              - TRUE if successful.
 * Argument         : UINT_PTR idTimer  - Timer identifier.
 **/
BOOL CSchedule::StopTimer(UINT_PTR idTimer)
{
    for(int i = 0; i < s_veclpSchd.size(); i++)
    {
        // Find pointer to schedule object.
        CSchedule* lpSchd = s_veclpSchd[i];
        if(lpSchd->m_idTimer == idTimer)
        {
            // Stop schedule object timer.
            if( ::KillTimer(NULL, idTimer) )
            {
                // Remove pointer to schedule object from container.
                lpSchd->m_idTimer = 0;
                s_veclpSchd.erase(s_veclpSchd.begin()+i);
                return TRUE;
            }
            else
                return FALSE;
        }
    }
    return FALSE;
}
