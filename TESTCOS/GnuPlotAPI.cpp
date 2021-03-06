
#include "stdafx.h"
#include "GnuPlotAPI.h"


int CGnuPlotAPI::TERM_CNT = 0;

CGnuPlotAPI::CGnuPlotAPI()
{
	m_pltpath = ReturnPath() ;
	TERM_CNT++;
	this->m_pltID = TERM_CNT;

	/* hide window */
	hw_CMD = FindWindow(NULL, _T("c:\\Windows\\system32\\cmd.exe"));
	ShowWindow(hw_CMD, SW_HIDE);
}

CGnuPlotAPI::~CGnuPlotAPI()
{
	if (m_fp != NULL)
	{
		_pclose(m_fp);
		m_fp = NULL;
	}
}

string    CGnuPlotAPI::ReturnPath()
{
	 

	char path[256];		
	GetModuleFileName(NULL, (LPWSTR)path, MAX_PATH);
	USES_CONVERSION;
	string    sPath(W2A((LPWSTR)path));
	int    nPos,lenth;
	nPos = sPath.find_last_of('\\');
	lenth = sPath.length();
	sPath = sPath.erase(nPos, lenth - nPos) + "\\Gnuplot\\gnuplot.exe";
	return    sPath;
}

bool CGnuPlotAPI::Open()
{
	USES_CONVERSION;
	const char *path = m_pltpath.c_str();

	if (!_access(m_pltpath.c_str(), 0))
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
void	CGnuPlotAPI::Plot(string _str)
{
	fprintf(m_fp, _str.c_str());
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

void CGnuPlotAPI::Fls()
{
	fflush(m_fp);
}

void CGnuPlotAPI::SetCurrentWnd()
{
	fprintf(m_fp, "set term wx %d\n",m_pltID);
}

int CGnuPlotAPI::MallocPlotData(int _type)
{
	///* memory allocation */
	//switch (_type) {
	//case PLT_Y:
	//	if (!(m_y = (double*)malloc(sizeof(double)*m_ny))) {
	//		//SDRPRINTF("error: initsdrplot memory allocation\n");
	//		return -1;
	//	}
	//	break;
	//case PLT_XY:
	//	if (!(m_x = (double*)malloc(sizeof(double)*m_nx)) ||
	//		!(m_y = (double*)malloc(sizeof(double)*m_nx))) {
	//		//SDRPRINTF("error: initsdrplot memory allocation\n");
	//		return -1;
	//	}
	//	break;
	//case PLT_SURFZ:
	//	if (!(m_z = (double*)malloc(sizeof(double)*m_nx*m_ny))){
	//		//SDRPRINTF("error: initsdrplot memory allocation\n");
	//		return -1;
	//	}
	//	break;
	//default:
	//	break;
	//}
	return 0;

}
/* plot 1D function ------------------------------------------------------------
* gnuplot plot 1D data function
* args   : FILE   *fp       I   gnuplot pipe handle
*          double *y        I   y data
*          int    n         I   number of input data
*          int    skip      I   number of skip data (0: plot all data)
*          double s         I   scale factor of y data
* return : none
*-----------------------------------------------------------------------------*/
void CGnuPlotAPI::plot(double *y, int n)
{
	int i;
	fprintf(m_fp, "set grid\n");
	fprintf(m_fp, "unset key\n");
	fprintf(m_fp, "plot '-' with lp lw 1 pt 6 ps 2\n");
	for (i = 0; i<n; i ++)
		fprintf(m_fp, "%.3f\n", y[i]);
	fprintf(m_fp, "e\n");
	fflush(m_fp);
}
/* plot 2D function ------------------------------------------------------------
* gnuplot plot 2D data function
* args   : FILE   *fp       I   gnuplot pipe handle
*          double *x        I   x data
*          double *y        I   y data
*          int    n         I   number of input data
*          int    skip      I   number of skip data (0: plot all data)
*          double s         I   scale factor of y data
* return : none
*-----------------------------------------------------------------------------*/
void CGnuPlotAPI::plot(double *x, double *y, int n)
{
	int i;
	fprintf(m_fp, "set grid\n");
	fprintf(m_fp, "unset key\n");
	fprintf(m_fp, "plot '-' with lines lt 1\n");
	for (i = 0; i<n; i ++)
		fprintf(m_fp, "%.3f\t%.3f\n", x[i], y[i]);
	fprintf(m_fp, "e\n");
	fflush(m_fp);
}
void CGnuPlotAPI::AddLine(PltLine* _line)
{

}