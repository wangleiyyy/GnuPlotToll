// TESTCOS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include "GnuPlotAPI.h"

double *datax,*datay;
int _tmain(int argc, _TCHAR* argv[])
{
	gnuplotapi_t gnuplt1;
	gnuplotapi_t gnuplt2;
	datax = (double*)malloc(sizeof(double)* 1000);
	datay = (double*)malloc(sizeof(double)* 1000);
	int i=0,j=0;




		if (gnuplt1.Open())
		{
			gnuplt1.SetCurrentWnd();

		//while (1)
			{
				for (i = 0; i < 1000; i++)
				{
					datax[i] = i;
					datay[i] = i *0.1;
				}
				gnuplt1.plot(datay,datax, 1000);
				//gnuplt1.Plot("plot sin(x),cos(x)\n");
				gnuplt1.Fls();
				j++;
				Sleep(100);
				if (j == 100)
				{
					//break;
				}
			}

		}

	
	getchar();

	//if (gnuplt2.Open())
	//{
	//	gnuplt2.SetCurrentWnd();
	//	gnuplt2.Plot("plot sin(x)\n");
	//	gnuplt2.Fls();
	//}
	//getchar();

	//gnuplt1.SetCurrentWnd();
	//gnuplt1.Plot("plot tan(x)\n");
	//gnuplt1.Fls();


	getchar();

	//sdrplt_t pltt;
	//int i = 0;
	////initsdrplot(&pltt);
	//pltt.y = (double*)malloc(sizeof(double)* 10);

	//for (i = 0; i < 10; i++)
	//{
	//	*(pltt.y + i) = i;
	//}


	//pltt.fp = _popen("D:\\Progra~1\\gnuplot\\bin\\gnuplot.exe", "w");
	////pltt.fp = _popen("D:\\MyPrj\\15_GPS_INS\\GNSS-SDRLIB\\cli\\win\\x64\\Debug\\gnuplot\\gnuplot.exe", "w");


	//fprintf(pltt.fp, "plot(sin(x))  \n");
	////for (i = 0; i< 10; i += (0 + 1))
	////	fprintf(pltt.fp, "%.3f\n", pltt.y[i]);
	////fprintf(pltt.fp, "e\n");
	//fflush(pltt.fp);

	//getchar();

	//if (pltt.fp != NULL)
	//{
	//	_pclose(pltt.fp);
	//	pltt.fp = NULL;
	//}


	return 0;
}

