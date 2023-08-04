#include <iostream>
#include "tetrahedral.h"
#include <string>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <time.h>
using namespace Eigen;
using namespace std;


double** new2DDouble(int col, int lin);
int** new2DInt(int col, int lin);
double* getcntr(FEM& Body);
double** getJmx(FEM& Body);
void initialize(FEM& BodyA, FEM& BodyB);
double getRand();


class Point
{
public:
	double x;
	double y;
	double z;
	Point(double x, double y, double z);
};

Point::Point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double cal_volume(Point a, Point b, Point c, Point d)
{
	Point p_ad(a.x - d.x, a.y - d.y, a.z - d.z);
	Point p_bd(b.x - d.x, b.y - d.y, b.z - d.z);
	Point p_cd(c.x - d.x, c.y - d.y, c.z - d.z);
	Point p_bd_cd(p_bd.y * p_cd.z - p_bd.z * p_cd.y, p_bd.z * p_cd.x - p_bd.x * p_cd.z, p_bd.x * p_cd.y - p_cd.x * p_bd.y);
	double res = abs(p_ad.x * p_bd_cd.x + p_ad.y * p_bd_cd.y + p_ad.z * p_bd_cd.z)/6.0;		// calculate the volume expand as the first row
	return res;
}



void initialize(FEM& BodyA, FEM& BodyB)
{
	BodyA.ND_FCOORD = new2DDouble(BodyA.NNODE,3);
	BodyA.ND_TCOORD = new2DDouble(BodyA.NNODE, 3);
	for (int i = 0; i < BodyA.NNODE; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			BodyA.ND_FCOORD[i][j] = 0.005*(getRand()-1.0);
			BodyA.ND_TCOORD[i][j] = BodyA.ND_COORD[i][j] + BodyA.ND_FCOORD[i][j];
		}
	}

	BodyA.ELM_E = new double[BodyA.NELEM];
	for (int i = 0; i < BodyA.NELEM; i++)
	{
		BodyA.ELM_E[i] = 1000000.0;  //10^6
	}



}

double getRand()
{
	srand(time(NULL));
	int iRand = rand();
	iRand %= 10000;
	iRand = iRand / 10000.0;
	return iRand;
}







void inputFE(FEM& BodyA , FEM& BodyB)
{

	const char* fileA = "D:\\BaiduNetdiskWorkspace\\flexible dynamic\\c code\\CPP\\a153.fe";
	const char* fileB = "D:\\BaiduNetdiskWorkspace\\flexible dynamic\\c code\\CPP\\b55.fe";

	read_file(fileA,BodyA);
	read_file(fileB,BodyB);




	BodyA.cntr = getcntr(BodyA);
	cout << BodyA.cntr[0]<<"\n" << BodyA.cntr[1] <<"\n"<< BodyA.cntr[2]<<endl;
	for (int i =0; i<BodyA.NNODE; i++)
	{
		BodyA.ND_COORD[i][0] -= BodyA.cntr[0];
		BodyA.ND_COORD[i][1] -= BodyA.cntr[1];
		BodyA.ND_COORD[i][2] -= BodyA.cntr[2];
	}
	BodyA.cntr = getcntr(BodyA);


	BodyB.cntr = getcntr(BodyB);
	for (int i = 0; i < BodyB.NNODE; i++)
	{
		BodyB.ND_COORD[i][0] -= BodyB.cntr[0];
		BodyB.ND_COORD[i][1] -= BodyB.cntr[1];
		BodyB.ND_COORD[i][2] -= BodyB.cntr[2];
	}
	BodyB.cntr = getcntr(BodyB);


	//cout << BodyA.cntr[0] << "\n" << BodyA.cntr[1] << "\n" << BodyA.cntr[2]<<endl;
	//BodyA.J = getJmx(BodyA);
	//cout << BodyA.J[0][0] << "\t" << BodyA.J[0][1] << "\t" << BodyA.J[0][2] << endl;
	//cout << BodyA.J[1][0] << "\t" << BodyA.J[1][1] << "\t" << BodyA.J[1][2] << endl;
	//cout << BodyA.J[2][0] << "\t" << BodyA.J[2][1] << "\t" << BodyA.J[2][2] << endl;

	// 
	//Matrix3d J;
	//J << BodyA.J[0][0], BodyA.J[0][1], BodyA.J[0][2], 
	//	BodyA.J[1][0], BodyA.J[1][1], BodyA.J[1][2], 
	//	BodyA.J[2][0], BodyA.J[2][1],BodyA.J[2][2];

	//EigenSolver<MatrixX3d> es(J);

	//Matrix3d D = es.pseudoEigenvalueMatrix();
	//Matrix3d V = es.pseudoEigenvectors();
	//cout << "The pseudo-eigenvalue matrix D is:" << endl << D << endl;
	//cout << "The pseudo-eigenvector matrix V is:" << endl << V << endl;








}



void read_file(const char* file_name, FEM &Body)
{
	FILE* fp;

	//	file input
	cout << "inputFE" << endl;
	errno_t err = fopen_s(&fp, file_name, "r");
	if (err != 0)
	{
		cout << "Cannot open input file. Strike any key exit!--inputdataplate.cpp inputPlate error" << endl;
		getchar();
		exit(1);
	}
	else
	{
		cout << "input file  succesfully  return code: " << err << endl;
	}
	fscanf_s(fp, "%lf", &Body.totalm);
	Body.cntr = new double[3];
	for (int i = 0; i < 3; i++)
	{
		fscanf_s(fp, "%lf", &Body.cntr[i]);
	}
	Body.J = new2DDouble(3, 3);	// need to alloc memory for array and matrix
	for (int i = 0; i < 3; i++)
	{
		fscanf_s(fp, "%lf %lf %lf", &Body.J[i][0], &Body.J[i][1], &Body.J[i][2]);
	}
	fscanf_s(fp, "%d %d %d %d", &Body.NF_NODE, &Body.NF, &Body.NNODE, &Body.NELEM);
	Body.F_COORD = new2DDouble(Body.NF_NODE, 3);
	for (int i = 0; i < Body.NF_NODE; i++)
	{
		fscanf_s(fp, "%lf %lf %lf", &Body.F_COORD[i][0], &Body.F_COORD[i][1], &Body.F_COORD[i][2]);
	}
	Body.F_ORD = new2DInt(Body.NF, 3);
	for (int i = 0; i < Body.NF; i++)
	{
		fscanf_s(fp, "%d %d %d", &Body.F_ORD[i][0], &Body.F_ORD[i][1], &Body.F_ORD[i][2]);
	}
	Body.ND_ROU = new double[Body.NNODE];
	Body.ND_M = new double[Body.NNODE];
	Body.ND_COORD = new2DDouble(Body.NNODE, 3);
	for (int i = 0; i < Body.NNODE; i++)
	{
		fscanf_s(fp, "%lf %lf %lf %lf %lf", &Body.ND_ROU[i], &Body.ND_M[i], &Body.ND_COORD[i][0], &Body.ND_COORD[i][1], &Body.ND_COORD[i][2]);
	}
	Body.ELM_ORD = new2DInt(Body.NELEM, 4);
	Body.ELM_V = new double[Body.NELEM];
	Body.ELM_ROU = new double[Body.NELEM];
	Body.ELM_M = new double[Body.NELEM];
	for (int i = 0; i < Body.NELEM; i++)
	{
		fscanf_s(fp, "%d %d %d %d %lf", &Body.ELM_ORD[i][0], &Body.ELM_ORD[i][1], &Body.ELM_ORD[i][2], &Body.ELM_ORD[i][3], &Body.ELM_V[i]);
	}
	fclose(fp);
	cout <<file_name<< " input ending\n";


	//	calculate ELM.V  ELM.M  ELM.ROU
	// calculate nodal mass
	for (int i = 0; i < Body.NNODE; i++)
	{
		Body.ND_M[i] = 0.0;
	}

	for (int i = 0; i < Body.NELEM; i++)
	{
		Point p1(Body.ND_COORD[Body.ELM_ORD[i][0]][0], Body.ND_COORD[Body.ELM_ORD[i][0]][1], Body.ND_COORD[Body.ELM_ORD[i][0]][2]);
		Point p2(Body.ND_COORD[Body.ELM_ORD[i][1]][0], Body.ND_COORD[Body.ELM_ORD[i][1]][1], Body.ND_COORD[Body.ELM_ORD[i][1]][2]);
		Point p3(Body.ND_COORD[Body.ELM_ORD[i][2]][0], Body.ND_COORD[Body.ELM_ORD[i][2]][1], Body.ND_COORD[Body.ELM_ORD[i][2]][2]);
		Point p4(Body.ND_COORD[Body.ELM_ORD[i][3]][0], Body.ND_COORD[Body.ELM_ORD[i][3]][1], Body.ND_COORD[Body.ELM_ORD[i][3]][2]);

		double V = cal_volume(p1, p2, p3, p4);
		Body.ELM_V[i] = V;					// volume
		//cout << V << endl;
		Body.ELM_ROU[i] = 2.146000000000000e+03;
		Body.ELM_M[i] = Body.ELM_ROU[i] * Body.ELM_V[i];
		//cout << Body.ELM_M[i] << endl;


		Body.ND_M[Body.ELM_ORD[i][0]] += Body.ELM_M[i] / 4.0;
		Body.ND_M[Body.ELM_ORD[i][1]] += Body.ELM_M[i] / 4.0;
		Body.ND_M[Body.ELM_ORD[i][2]] += Body.ELM_M[i] / 4.0;
		Body.ND_M[Body.ELM_ORD[i][3]] += Body.ELM_M[i] / 4.0;
	}
	cout <<file_name<< " FEM Initiallize ending\n";


	//for (int i = 0; i < Body.NNODE; i++)
	//{
	//	cout << Body.ND_M[i] << endl;
	//}

}
