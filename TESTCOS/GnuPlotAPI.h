#ifndef _GNU_PLOT_API_H
#define _GNU_PLOT_APT_H


#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <atlstr.h>
#include <io.h>
#include <list>
using namespace std;

/*plotting setting */

#define PLT_Y         1                /* plotting type: 1D data */
#define PLT_XY        2                /* plotting type: 2D data */
#define PLT_SURFZ     3                /* plotting type: 3D surface data */
#define PLT_BOX       4                /* plotting type: BOX */
#define PLT_WN        5                /* number of figure window column */
#define PLT_HN        4                /* number of figure window row */
#define PLT_W         200              /* window width (pixel) */
#define PLT_H         300              /* window height (pixel) */
#define PLT_MW        100              /* margin (pixel) */
#define PLT_MH        20                /* margin (pixel) */
#define PLT_MS        200              /* plotting interval (ms) */
#define PLT_MS_FILE   1000               /* plotting interval (ms) */

struct PltPoint
{
	int point_type;
	int point_size;
};

struct PltData
{
	int m_nx;              /* length of x data */
	int m_ny;              /* length of y data */
	double *m_x;           /* x data */
	double *m_y;           /* y data */
	double *m_z;           /* z data */
	int m_flagabs;         /* y axis data absolute flag (y=abs(y)) */
	double m_scale;        /* y axis data scale (y=scale*y) */
};

struct PltLine
{
	int line_style;
	int line_type;
	int line_width;
	int line_color;
	PltPoint point;
	PltData	 data;
};

struct PltWnd
{
	int m_plth;            /* plot window height */
	int m_pltw;            /* plot window width */
	int m_pltmh;           /* plot window margin height */
	int m_pltmw;           /* plot window margin width */
};

typedef list<PltLine> Line;

/* sdr plotting struct */
typedef class CGnuPlotAPI
{
public:
	CGnuPlotAPI();
	HWND	  hw_CMD;             /* window handle */
	CString   ReturnPath();
	PltWnd	  m_pltWnd;
	PltLine   m_line;
	void	Plot(CString _str);
	bool	Open();
	void	Fls();
	void	SetXRange(double xmin, double xmax);
	void	SetYRange(double ymin, double ymax);
	void	SetCurrentWnd();
	void	IniPlotData();
	int		MallocPlotData(int _type);
	void	plot(double *y, int n);
	void	plot(double *x, double *y, int n);
	void    AddLine(PltLine* _line);
	~CGnuPlotAPI();
private:
	FILE		*m_fp;            /* file pointer (gnuplot pipe) */
	CString		m_pltpath;
	int			m_isOpen;
	int m_pltID;           /* number of figure */
	int m_type;            /* plotting type (PLT_X/PLT_XY/PLT_SURFZ) */
	int m_skip;            /* skip data (0: plotting all data) */
	double m_pltms;        /* plot interval (ms) */
	static int TERM_CNT;
} gnuplotapi_t;



#endif