#include <iostream>
#include "tetrahedral.h"
using namespace std;


void inputFE(FEM& a, FEM& b);
void EF2BP_sim(FEM& a, FEM& b);
void initialize(FEM& BodyA, FEM& BodyB);
int calculate(FEM& BodyA, FEM& BodyB);

void EF2BP_sim(FEM& BodyA,FEM& BodyB)
{
	inputFE(BodyA, BodyB);
	initialize(BodyA, BodyB);
	calculate(BodyA,BodyB);

}