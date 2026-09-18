#if !defined(AFX_SERIALPORT_H__0DCE7CC1_2426_4BDF_9AFC_410B32D9FE74__INCLUDED_)
#define AFX_SERIALPORT_H__0DCE7CC1_2426_4BDF_9AFC_410B32D9FE74__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SerialPort.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSerialPort window
//////////////////////////////////////////////////////////////////////
// SerialPort.h: implementation of the CSerialPort class.

class CSerialPort : public CWnd
{
// Construction
public:
	CSerialPort();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialPort)
	//}}AFX_VIRTUAL

	static void ThrowSerialException(DWORD dwError = 0);
// Implementation
public:
	void ClosePort();
	void ClosePort1();
	void ClearWriteBuffer();
    void ClearReadBuffer();
	void Purge(DWORD dwFlags);
	BOOL ReadByte(BYTE &rx);
	BOOL WriteByte(BYTE bybyte);
	BOOL WriteByte1(BYTE *bybyte, unsigned short int size);
	BOOL OpenPort(CString portname);
	BOOL IsOpen() const { return hComm != INVALID_HANDLE_VALUE; };
	BOOL SetCommunicationTimeouts(DWORD ReadIntervalTimeout,DWORD ReadTotalTimeoutMultiplier,DWORD ReadTotalTimeoutConstant,DWORD WriteTotalTimeoutMultiplier,DWORD WriteTotalTimeoutConstant);
	BOOL ConfigurePort(DWORD BaudRate,BYTE ByteSize,DWORD fParity,BYTE  Parity,BYTE StopBits);
	HANDLE hComm;
	DCB      m_dcb;
	COMMTIMEOUTS m_CommTimeouts;
	BOOL     m_bPortReady;
	BOOL     bWriteRC;
	BOOL     bReadRC;
	DWORD iBytesWritten;
	DWORD iBytesRead;
	DWORD dwBytesRead;
	virtual ~CSerialPort();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSerialPort)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void InitializeSerialPort(CString strComPort, bool bMode);
	void FlushPCSerialPort(CString strComPort);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALPORT_H__0DCE7CC1_2426_4BDF_9AFC_410B32D9FE74__INCLUDED_)
