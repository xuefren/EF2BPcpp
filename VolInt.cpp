#include "tetrahedral.h"
#include <math.h>
#include <iostream>
using namespace std;

double** new2DDouble(int col, int lin);

double* getcntr(FEM& Body)
{



	double* cntr = new double [3];
	double totalm = Body.totalm;
	for (int i = 0; i < 3; i++)
	{
		cntr[i] = 0;
	}

	for (int i = 0; i<Body.NNODE; i++) 
	{

		cntr[0] += (Body.ND_COORD[i][0] * Body.ND_M[i]);
		cntr[1] += (Body.ND_COORD[i][1] * Body.ND_M[i]);
		cntr[2] += (Body.ND_COORD[i][2] * Body.ND_M[i]);

		//cout << Body.ND_COORD[i][0] << "\t" << Body.ND_COORD[i][1] << "\t" << Body.ND_COORD[i][2] << endl;
	}



	cntr[0] = cntr[0] / totalm;
	cntr[1] = cntr[1] / totalm;
	cntr[2] = cntr[2] / totalm;

	return cntr;
}

double** getJmx(FEM& Body)
{
	double** Jmx = new2DDouble(3,3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Jmx[i][j] = 0;
		}
	}
	for (int i = 0; i<Body.NNODE; i++)
	{
		Jmx[0][0] += (pow(Body.ND_COORD[i][1], 2) + pow(Body.ND_COORD[i][2], 2)) * Body.ND_M[i];
		Jmx[1][1] += (pow(Body.ND_COORD[i][0], 2) + pow(Body.ND_COORD[i][2], 2)) * Body.ND_M[i];
		Jmx[2][2] += (pow(Body.ND_COORD[i][1], 2) + pow(Body.ND_COORD[i][1], 2)) * Body.ND_M[i];
		Jmx[0][1] -= (Body.ND_COORD[i][0] * Body.ND_COORD[i][1]) * Body.ND_M[i];
		Jmx[0][2] -= (Body.ND_COORD[i][0] * Body.ND_COORD[i][2]) * Body.ND_M[i];
		Jmx[1][2] -= (Body.ND_COORD[i][1] * Body.ND_COORD[i][2]) * Body.ND_M[i];
	}
	Jmx[1][0] = Jmx[0][1];
	Jmx[2][0] = Jmx[0][2];
	Jmx[2][1] = Jmx[1][2];
	return Jmx;
}