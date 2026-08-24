// Schedule.h: interface for the CSchedule class.
//
/////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCHEDULE_H__0866789D_E8D1_480D_9DD5_0B1F2B1992CC__INCLUDED_)
#define AFX_SCHEDULE_H__0866789D_E8D1_480D_9DD5_0B1F2B1992CC__INCLUDED_

#include <windows.h>
#include <vector>

/**
 * EN_SCHEDULE_TIMES - predefined schedule times in milliseconds. Use as an aid.
 * User may specify own schedule times.
 **/
enum EN_SCHEDULE_TIMES
{
    BY_01_SECONDS = 1000 * 1,
    BY_02_SECONDS = 1000 * 2,
	BY_03_SECONDS = 1000 * 3,
    BY_05_SECONDS = 1000 * 5,
    BY_10_SECONDS = 1000 * 10,
    BY_20_SECONDS = 1000 * 20,
    BY_30_SECONDS = 1000 * 30,
    BY_60_SECONDS = 1000 * 60,
    BY_01_MINUTES = 1000 * 60 * 1,
    BY_02_MINUTES = 1000 * 60 * 2,
	BY_03_MINUTES = 1000 * 60 * 3,
    BY_05_MINUTES = 1000 * 60 * 5,
    BY_10_MINUTES = 1000 * 60 * 10,
    BY_20_MINUTES = 1000 * 60 * 20,
    BY_30_MINUTES = 1000 * 60 * 30,
    BY_60_MINUTES = 1000 * 60 * 60,
    BY_01_HOURS   = 1000 * 60 * 60 * 1,
    BY_02_HOURS   = 1000 * 60 * 60 * 2,
    BY_03_HOURS   = 1000 * 60 * 60 * 3,
    BY_04_HOURS   = 1000 * 60 * 60 * 4,
    BY_06_HOURS   = 1000 * 60 * 60 * 6,
    BY_08_HOURS   = 1000 * 60 * 60 * 8,
    BY_12_HOURS   = 1000 * 60 * 60 * 12,
    BY_24_HOURS   = 1000 * 60 * 60 * 24,
    BY_01_DAYS    = 1000 * 60 * 60 * 24 * 1,
};

/**
 * CSchedule class - schedules function calls or post messages.
 **/
class CSchedule
{
public:
	CSchedule();
	virtual ~CSchedule();

    BOOL        StartSchedule();
    BOOL        StopSchedule();

    BOOL        SetScheduleTime(DWORD dwScheduleTime);
    VOID        SetScheduleFunction(VOID(*fn)(int),int);
    VOID        SetPostMessage(HWND hWnd, UINT uMsg,
                               WPARAM wParam, LPARAM lParam);

protected:
    virtual VOID ScheduleProcess();         // Overide to call own process.

private:
    UINT_PTR    m_idTimer;                  // Timer identification.
    DWORD       m_dwScheduleTime;           // Scheduled time to run process.
	int			Value_ToSend;

    // PostMessage required parameters
    HWND        m_hWnd;                     // Handle to destination window.
    UINT        m_uMsg;
    WPARAM      m_wParam;
    LPARAM      m_lParam;
	static DWORD	m_ulTickCount;
	static DWORD	m_ulSchTime;

    // Scheduled function to call.
    VOID     (* m_fnScheduledFunction)(int);

    // Container for scheduled objects.
    static std::vector<CSchedule*>  s_veclpSchd;

    static VOID CALLBACK GlobalTimerProcess(HWND hWnd, UINT uMsg,
                                            UINT_PTR idTimer, DWORD dwTime);
    static BOOL StartTimer(CSchedule* lpSchd);
    static BOOL StopTimer(UINT_PTR idTimer);
};


#endif // !defined(AFX_SCHEDULE_H__0866789D_E8D1_480D_9DD5_0B1F2B1992CC__INCLUDED_)
