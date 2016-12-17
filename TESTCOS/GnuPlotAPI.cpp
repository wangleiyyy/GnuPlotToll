
#include "stdafx.h"
#include "GnuPlotAPI.h"


int CGnuPlotAPI::TERM_CNT = 0;

CGnuPlotAPI::CGnuPlotAPI()
{
	m_pltpath = CGnuPlotAPI::ReturnPath() + "\\Gnuplot\\gnuplot.exe";
	TERM_CNT++;
	this->m_pltID = TERM_CNT;

	/* hide window */
	//hw_CMD = FindWindow(NULL, _T("c:\\Windows\\system32\\cmd.exe"));
	//ShowWindow(hw_CMD, SW_HIDE);
}
CGnuPlotAPI::~CGnuPlotAPI()
{
	if (m_fp != NULL)
	{
		_pclose(m_fp);
		m_fp = NULL;
	}
}

CString    CGnuPlotAPI::ReturnPath()
{
	CString    sPath;
	GetModuleFileName(NULL, sPath.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	sPath.ReleaseBuffer();
	int    nPos;
	nPos = sPath.ReverseFind('\\');
	sPath = sPath.Left(nPos);
	return    sPath;
}

bool CGnuPlotAPI::Open()
{
	USES_CONVERSION;
	char *path = T2A(m_pltpath);

	if (!_access(path, 0))
	{
		m_fp = _popen(path, "w");
		if (m_fp == NULL)
		{
			m_isOpen = false;
		}
		else
		{
			m_isOpen = true;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void	CGnuPlotAPI::Plot(CString _str)
{
	USES_CONVERSION;
	fprintf(m_fp, T2A(_str));
}


/* gnuplot set x axis range ----------------------------------------------------
* set x axis range
* args   : sdrplt_t *plt    I   sdr plot struct
*          double *xmin     I   minimum value in x-axis
*          double *xmax     I   maximum value in x-axis
* return : none
*-----------------------------------------------------------------------------*/
void CGnuPlotAPI::SetXRange( double xmin, double xmax)
{
	fprintf(m_fp, "set xr[%.1f:%.1f]\n", xmin, xmax);
}
/* gnuplot set y axis range ----------------------------------------------------
* set y axis range
* args   : sdrplt_t *plt    I   sdr plot struct
*          double *ymin     I   minimum value in y-axis
*          double *ymax     I   maximum value in y-axis
* return : none
*-----------------------------------------------------------------------------*/
void CGnuPlotAPI::SetYRange( double ymin, double ymax)
{
	fprintf(m_fp, "set yr[%.1f:%.1f]\n", ymin, ymax);
}
void	CGnuPlotAPI::Fls()
{
	fflush(m_fp);
}
void	CGnuPlotAPI::SetCurrentWnd()
{
	fprintf(m_fp, "set term wx %d\n",m_pltID);
}
