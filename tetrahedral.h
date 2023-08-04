

typedef struct Element
{
	double totalm;
	double* cntr;
	double** J;

	int NF_NODE;
	double** F_COORD;

	int NF;
	int** F_ORD;

	int NNODE;
	double* ND_ROU;
	double* ND_M;
	double** ND_COORD;
	double** ND_FCOORD;
	double** ND_TCOORD;

	int NELEM;
	double* ELM_ROU;	//	need calculate
	double* ELM_V;		//	need calculate
	double* ELM_M;		//  need calculate
	double* ELM_E;
	int** ELM_ORD;
}FEM;
void read_file(const char* file_name, FEM &fe);