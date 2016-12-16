// TESTCOS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
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


int _tmain(int argc, _TCHAR* argv[])
{
	sdrplt_t pltt;
	int i = 0;
	//initsdrplot(&pltt);
	pltt.y = (double*)malloc(sizeof(double)* 10);

	for (i = 0; i < 10; i++)
	{
		*(pltt.y + i) = i;
	}


	pltt.fp = _popen("D:\\\Progra~1\\gnuplot\\bin\\gnuplot.exe", "w");
	//pltt.fp = _popen("D:\\MyPrj\\15_GPS_INS\\GNSS-SDRLIB\\cli\\win\\x64\\Debug\\gnuplot\\gnuplot.exe", "w");


	fprintf(pltt.fp, "plot(sin(x))  \n");
	//for (i = 0; i< 10; i += (0 + 1))
	//	fprintf(pltt.fp, "%.3f\n", pltt.y[i]);
	//fprintf(pltt.fp, "e\n");
	fflush(pltt.fp);

	getchar();

	if (pltt.fp != NULL)
	{
		_pclose(pltt.fp);
		pltt.fp = NULL;
	}


	return 0;
}

