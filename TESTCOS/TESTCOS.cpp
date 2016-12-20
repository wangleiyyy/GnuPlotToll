// TESTCOS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include "GnuPlotAPI.h"
#include <string>
string gnupltstrproc(int cols, int colstartIndex, string filename)
{
	string gnupltstr = string("plot ");

	//string("plot '") + filename + "' using " + to_string(col) + " with lines\n"

	for (int i = 0; i < cols; i++)
	{
		gnupltstr += "'" + filename + "' using " + to_string(colstartIndex + i) + " with lines, ";
	}
	gnupltstr += string("\n");


	return gnupltstr;
}

int _tmain(int argc, _TCHAR* argv[])
{
	double *datax, *datay;
	gnuplotapi_t gnuplt1;
	gnuplotapi_t gnuplt2;
	datax = (double*)malloc(sizeof(double)* 1000);
	datay = (double*)malloc(sizeof(double)* 1000);
	int i=0,j=0;
	int cols;
	string datapath;
	string usingcmd;
	cout << "Please input the path of data:\n";
	cin.clear();
	getline(cin, datapath); //将当前行从缓存中取出

	while (1)
	{
		cout << "draw the col of data:\n";
		cin >> cols;
		if (cols == 0)
		{
			break;
		}

		if (cols < 11)
		{
			usingcmd = gnupltstrproc(1, cols, datapath);
		}
		else
		{
			usingcmd = gnupltstrproc(cols / 10 , cols % 10, datapath);
		}


		//switch (cols)
		//{
		//case 31:
		//	usingcmd = gnupltstrproc(3, 2, datapath);
		//	break;
		//case 34:
		//	usingcmd = gnupltstrproc(3, 5, datapath);
		//	break;
		//case 37:
		//	usingcmd = gnupltstrproc(3, 7, datapath);
		//	break;
		//case 0:
		//	goto OUT_EXIT;
		//	break;
		//default:
		//	usingcmd = gnupltstrproc(1, cols, datapath);
		//	break;
		//}


		//cout << "plot col:" + col +string("\n") ;
		

		if (gnuplt1.Open())
		{
			gnuplt1.SetCurrentWnd();
			//gnuplt1.Plot(("plot '") + datapath + "' using " + to_string( col )+ " with lines\n");
			gnuplt1.Plot(usingcmd);

			gnuplt1.Fls();
		}


	}


	

OUT_EXIT:


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


	//getchar();

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

