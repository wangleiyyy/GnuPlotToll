
// GnuplotToolDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxeditbrowsectrl.h"

/* sdr plotting struct */
typedef struct {
	FILE *fp;            /* file pointer (gnuplot pipe) */
#ifdef WIN32
	HWND hw;             /* window handle */
#endif
	int nx;              /* length of x data */
	int ny;              /* length of y data */
	double *x;           /* x data */
	double *y;           /* y data */
	double *z;           /* z data */
	int type;            /* plotting type (PLT_X/PLT_XY/PLT_SURFZ) */
	int skip;            /* skip data (0: plotting all data) */
	int flagabs;         /* y axis data absolute flag (y=abs(y)) */
	double scale;        /* y axis data scale (y=scale*y) */
	int plth;            /* plot window height */
	int pltw;            /* plot window width */
	int pltmh;           /* plot window margin height */
	int pltmw;           /* plot window margin width */
	int pltno;           /* number of figure */
	double pltms;        /* plot interval (ms) */
} sdrplt_t;
// CGnuplotToolDlg dialog
class CGnuplotToolDlg : public CDialogEx
{
// Construction
public:
	CGnuplotToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GNUPLOTTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	// gnuplot exe path
	CEdit m_edit_gpltpath;
	afx_msg void OnBnClickedBtnPathGplt();
	// edit browse control gnu path 
	CMFCEditBrowseCtrl m_ebc_gnupltpath;
	afx_msg void OnEnChangeEbc();

	CString selectedPath;
	sdrplt_t pltt;
};
