# include <iostream>
# include <cmath>
# include <conio.h>
# include <cstdlib>
# include <new>

double** new2DDouble(int col, int lin)
{
	double** newArray;

	newArray = new double* [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new double[lin];
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = 0.0;
		}
	}

	return newArray;
}
int** new2DInt(int col, int lin)
{
	int** newArray;

	newArray = new int* [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new int[lin];
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = 0;
		}
	}

	return newArray;
}

double*** new3DDouble(int col, int lin, int hei)
{
	double*** newArray;

	newArray = new double** [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new double* [lin];
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = new double[hei];
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			for (int k = 0; k < hei; k++)
			{
				newArray[i][j][k] = 0.0;
			}
		}
	}

	return newArray;
}
int*** new3DInt(int col, int lin, int hei)
{
	int*** newArray;

	newArray = new int** [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new int* [lin];
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = new int[hei];
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			for (int k = 0; k < hei; k++)
			{
				newArray[i][j][k] = 0;
			}
		}
	}

	return newArray;
}
double**** new4DDouble(int col, int lin, int hei1, int hei2)
{
	double**** newArray;

	newArray = new double*** [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new double** [lin];
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = new double* [hei1];
			for (int k = 0; k < hei1; k++)
			{
				newArray[i][j][k] = new double[hei2];
			}
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			for (int k = 0; k < hei1; k++)
			{
				for (int m = 0; m < hei2; m++)
				{
					newArray[i][j][k][m] = 0.0;
				}
			}
		}
	}

	return newArray;
}
int**** new4DInt(int col, int lin, int hei1, int hei2)
{
	int**** newArray;

	newArray = new int*** [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new int** [lin];
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = new int* [hei1];
			for (int k = 0; k < hei1; k++)
			{
				newArray[i][j][k] = new int[hei2];
			}
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			for (int k = 0; k < hei1; k++)
			{
				for (int m = 0; m < hei2; m++)
				{
					newArray[i][j][k][m] = 0;
				}
			}
		}
	}

	return newArray;
}
double***** new5DDouble(int col, int lin, int hei1, int hei2, int hei3)
{
	double***** newArray;

	newArray = new double**** [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new double*** [lin];
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = new double** [hei1];
			for (int k = 0; k < hei1; k++)
			{
				newArray[i][j][k] = new double* [hei2];
				for (int m = 0; m < hei2; m++)
				{
					newArray[i][j][k][m] = new double[hei3];
				}
			}
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			for (int k = 0; k < hei1; k++)
			{
				for (int m = 0; m < hei2; m++)
				{
					for (int n = 0; n < hei3; n++)
					{
						newArray[i][j][k][m][n] = 0.0;
					}
				}
			}
		}
	}

	return newArray;
}
int***** new5DInt(int col, int lin, int hei1, int hei2, int hei3)
{
	int***** newArray;

	newArray = new int**** [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new int*** [lin];
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = new int** [hei1];
			for (int k = 0; k < hei1; k++)
			{
				newArray[i][j][k] = new int* [hei2];
				for (int m = 0; m < hei2; m++)
				{
					newArray[i][j][k][m] = new int[hei3];
				}
			}
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			for (int k = 0; k < hei1; k++)
			{
				for (int m = 0; m < hei2; m++)
				{
					for (int n = 0; n < hei3; n++)
					{
						newArray[i][j][k][m][n] = 0;
					}
				}
			}
		}
	}

	return newArray;
}
double****** new6DDouble(int col, int lin, int hei1, int hei2, int hei3, int hei4)
{
	double****** newArray;

	newArray = new double***** [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new double**** [lin];
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = new double*** [hei1];
			for (int k = 0; k < hei1; k++)
			{
				newArray[i][j][k] = new double** [hei2];
				for (int m = 0; m < hei2; m++)
				{
					newArray[i][j][k][m] = new double* [hei3];
					for (int l = 0; l < hei3; l++)
					{
						newArray[i][j][k][m][l] = new double[hei4];
					}
				}
			}
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			for (int k = 0; k < hei1; k++)
			{
				for (int m = 0; m < hei2; m++)
				{
					for (int n = 0; n < hei3; n++)
					{
						for (int l = 0; l < hei3; l++)
						{
							newArray[i][j][k][m][n][l] = 0.0;
						}
					}
				}
			}
		}
	}

	return newArray;
}
int****** new6DInt(int col, int lin, int hei1, int hei2, int hei3, int hei4)
{
	int****** newArray;

	newArray = new int***** [col];
	for (int i = 0; i < col; i++)
	{
		newArray[i] = new int**** [lin];
		for (int j = 0; j < lin; j++)
		{
			newArray[i][j] = new int*** [hei1];
			for (int k = 0; k < hei1; k++)
			{
				newArray[i][j][k] = new int** [hei2];
				for (int m = 0; m < hei2; m++)
				{
					newArray[i][j][k][m] = new int* [hei3];
					for (int l = 0; l < hei3; l++)
					{
						newArray[i][j][k][m][l] = new int[hei4];
					}
				}
			}
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			for (int k = 0; k < hei1; k++)
			{
				for (int m = 0; m < hei2; m++)
				{
					for (int n = 0; n < hei3; n++)
					{
						for (int l = 0; l < hei3; l++)
						{
							newArray[i][j][k][m][n][l] = 0;
						}
					}
				}
			}
		}
	}

	return newArray;
}