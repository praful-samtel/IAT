// SerialPort.cpp : implementation file
//

#include "stdafx.h"
#include "windows.h"
#include "SerialPort.h"
#include "Schedule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HANDLE haComm;
CSerialPort gCommPort1, gCommPort2, gCommPort5, gCommPort7,gCommPort3,gCommPort4,gCommPort6,gCommPort12;

/////////////////////////////////////////////////////////////////////////////
// SerialPort.cpp: implementation of the CSerialPort class.


// CSerialPort
unsigned char Byte2Write ,ByteReceived;

CSerialPort::CSerialPort()
{
}

CSerialPort::~CSerialPort()
{
}


BEGIN_MESSAGE_MAP(CSerialPort, CWnd)
	//{{AFX_MSG_MAP(CSerialPort)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSerialPort message handlers

BOOL CSerialPort::OpenPort(CString portname)
{
	portname= "//./" +portname;

	hComm = CreateFile(portname,
                      GENERIC_READ | GENERIC_WRITE,
                      0,
                      0,
                      OPEN_EXISTING,
                      0,
                      0);
	if(hComm==INVALID_HANDLE_VALUE)
	{
		return false;
	}
	else
		return true;
}

BOOL CSerialPort::ConfigurePort(DWORD BaudRate, BYTE ByteSize, DWORD fParity, BYTE Parity, BYTE StopBits)
{
	if((m_bPortReady = GetCommState(hComm, &m_dcb))==0)
	{
		CloseHandle(hComm);
		return false;
	}
	m_dcb.BaudRate =BaudRate;
	m_dcb.ByteSize = ByteSize;
	m_dcb.Parity =Parity;
	m_dcb.StopBits =StopBits;
	
#if 1
	m_dcb.fBinary=TRUE;
	m_dcb.fDsrSensitivity=false;
	m_dcb.fParity=fParity;
	m_dcb.fOutX=false;
	m_dcb.fInX=false;
	m_dcb.fNull=false;
	m_dcb.fAbortOnError=TRUE;
	m_dcb.fOutxCtsFlow=FALSE;
	m_dcb.fOutxDsrFlow=false;
	m_dcb.fDtrControl=DTR_CONTROL_DISABLE;
	m_dcb.fDsrSensitivity=false;
	m_dcb.fRtsControl=RTS_CONTROL_DISABLE;
	m_dcb.fOutxCtsFlow=false;
	m_dcb.fOutxCtsFlow=false;
#endif
	m_bPortReady = SetCommState(hComm, &m_dcb);
	if(m_bPortReady ==0)
	{
		CloseHandle(hComm);
		return false;
	}
	return true;
}

BOOL CSerialPort::SetCommunicationTimeouts(DWORD ReadIntervalTimeout, DWORD ReadTotalTimeoutMultiplier, DWORD ReadTotalTimeoutConstant, DWORD WriteTotalTimeoutMultiplier, DWORD WriteTotalTimeoutConstant)
{
	if((m_bPortReady = GetCommTimeouts (hComm, &m_CommTimeouts))==0)
	   return false;
	m_CommTimeouts.ReadIntervalTimeout =ReadIntervalTimeout;
	m_CommTimeouts.ReadTotalTimeoutConstant =ReadTotalTimeoutConstant;
	m_CommTimeouts.ReadTotalTimeoutMultiplier =ReadTotalTimeoutMultiplier;
	m_CommTimeouts.WriteTotalTimeoutConstant = WriteTotalTimeoutConstant;
	m_CommTimeouts.WriteTotalTimeoutMultiplier =WriteTotalTimeoutMultiplier;
	m_bPortReady = SetCommTimeouts (hComm, &m_CommTimeouts);
	if(m_bPortReady ==0)
	{
		CloseHandle(hComm);
		return false;
	}
	haComm = hComm;
	//hComm = NULL;
	//BYTE bybyte = 'A';
	//if(WriteFile(hComm,&bybyte,1,&iBytesWritten,NULL)==0)
		//return false;
	return true;
	
}

BOOL CSerialPort::WriteByte(BYTE bybyte)
{
	iBytesWritten=0;
	if ( 0 == bybyte )
	{
		return false;
	}
	if(WriteFile(hComm,&bybyte,1,&iBytesWritten,NULL)==0)
		return false;
	else 
		return true;
}

BOOL CSerialPort::WriteByte1(BYTE *bybyte, unsigned short int size)
{

	iBytesWritten=0;
	if ( 0 == bybyte )
	{
		return false;
	}
	if(WriteFile(haComm,bybyte,size,&iBytesWritten,NULL)==0)
		return false;
	else 
		return true;
}

BOOL CSerialPort::ReadByte(BYTE	&rx)
{
	 //BYTE rx;
	 COMSTAT status;
	 
	 
DWORD dwBytesTransferred=0;

//portname.GetStatus(status);
//rx.ClearReadBuffer();

if (ReadFile(hComm, &rx, 1, &dwBytesTransferred, 0))
{
	//if (rx > 64)
	{
	do
	{
    if (dwBytesTransferred == 1)
	{
     ByteReceived=rx;
     return true;
	
	}
	}while(rx =='0');
	}
	/*else
	{
		AfxMessageBox(_T("CSerialPort::Read, Failed Error"));
	}*/
}
     
 return false;
  
}
void CSerialPort::ClearWriteBuffer()
{
  Purge(PURGE_TXCLEAR);
}

void CSerialPort::ClearReadBuffer()
{
  Purge(PURGE_RXCLEAR);
}

void CSerialPort::Purge(DWORD dwFlags)
{
  //Validate our parameters
//  ASSERT(IsOpen());

  if (!PurgeComm(hComm, dwFlags))
  {
    DWORD dwLastError = GetLastError();
    TRACE(_T("CSerialPort::Purge, Failed in call to PurgeComm, Error:%d\n"), dwLastError);
    ThrowSerialException(dwLastError);
  }
}
void CSerialPort::ClosePort()
{
	CloseHandle(hComm);	
	//AfxMessageBox("Close port error");
	return;
}
void CSerialPort::ClosePort1()
{
	CloseHandle(haComm);
	//AfxMessageBox("Close port1 error");
	return;
}
void CSerialPort::ThrowSerialException(DWORD dwError)
{
	if (dwError == 0)
		dwError = ::GetLastError();

	//CSerialPort* pException = new CSerialPort (dwError);

	TRACE(_T("Warning: throwing CSerialException for error %d\n"), dwError);
	//THROW(pException);
}


void CSerialPort::InitializeSerialPort(CString strComPort, bool bMode)
{
	//IO CONTROL BOX com init
	if (strComPort.Compare("com1") == 0)
	{
		if (!gCommPort1.OpenPort(strComPort))
		{
			AfxMessageBox("Unable to open Serial Port com1");
		}
		//	return PORT_NOTOPEN;
		
		if (!gCommPort1.ConfigurePort(115200, 8, FALSE, 0, 0))
		{
			AfxMessageBox("Unable to open Serial Port");
		}
		//return PORTNOTCONFIGURED;
		
		if (!gCommPort1.SetCommunicationTimeouts(100, 1000, 0,0,0))
		{
			AfxMessageBox("Unable to open Serial Port");
		}
	}

	//interface com init
	else if (strComPort.Compare("com5") == 0)
	{
		if (!gCommPort5.OpenPort(strComPort))
		{
			//AfxMessageBox("Unable to open Serial Port com5");
		}
		//	return PORT_NOTOPEN;
		
		if (!gCommPort5.ConfigurePort(9600, 8, FALSE, 0, 0))
		{
				//AfxMessageBox("Unable to open Serial Port");
		}


		//return PORTNOTCONFIGURED;
		
		if (!gCommPort5.SetCommunicationTimeouts(100, 1000, 0,0,0))
		{
			//AfxMessageBox("Unable to open Serial Port");
		}
		//	return PORTOPENFAIL;
	}

	//Arinc429 com init
	
	else if (strComPort.Compare("com7") == 0)
	{
		if (!gCommPort7.OpenPort(strComPort))
		{
			//AfxMessageBox("Unable to open Serial Port com7");
		}
		//	return PORT_NOTOPEN;
		
		if (!gCommPort7.ConfigurePort(115200, 8, FALSE, 0, 0))
		{
			//("Unable to open Serial Port");
		}
		//return PORTNOTCONFIGURED;
		
		if (!gCommPort7.SetCommunicationTimeouts(100, 100, 0,0,0))
		{
			//AfxMessageBox("Unable to open Serial Port");
		}
	}	

	
}


void CSerialPort::FlushPCSerialPort(CString strComPort)
{
	BOOL bTrsFlag = true;
	unsigned char ucReadData1;
	
	if (strComPort.Compare("com1") == 0)
	{
		while(bTrsFlag)
		{
			bTrsFlag = gCommPort1.ReadByte(ucReadData1);
		}
	}
	else if (strComPort.Compare("com2") == 0)
	{
		while(bTrsFlag)
		{
			bTrsFlag = gCommPort2.ReadByte(ucReadData1);
		}
	}
	else if (strComPort.Compare("com5") == 0)
	{
		while(bTrsFlag)
		{
			bTrsFlag = gCommPort5.ReadByte(ucReadData1);
		}
	}
	else if (strComPort.Compare("com7") == 0)
	{
		while(bTrsFlag)
		{
			bTrsFlag = gCommPort7.ReadByte(ucReadData1);
		}
	}
	
}

