#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

#include "newmat11/newmatio.h"

using namespace std;

#ifdef use_namespace
using namespace NEWMAT;
#endif

class StatisticalTest
{
public:
	StatisticalTest();
	~StatisticalTest();

	enum eTEST { ADF_TEST, T_TEST, CHI_SQUARE_TEST }; //Need to add more 
	eTEST TestType;

	double** getZSurface() { return zSurfacePtr; }
	double* getNSample() { return nSample; }
	double* getProbability() { return Probability; }
	ReturnMatrix OLS(Matrix& x, Matrix& y);
	ReturnMatrix OLSError(Matrix& x, Matrix& y, ColumnVector& beta, int df);
	void adfTest(double* x, int obs, int k, double* dfs, double* pv);
	void GetNeighbourIndices(int n, double* inArr, double x, int* lx, int* ux);



private:
	double zSurface[6][8];
	double* zSurfacePtr[8];
	double nSample[6]{ 25, 50, 100, 250, 500, 10000 };
	double Probability[8]{ 0.01, 0.025, 0.05, 0.1, 0.9, 0.95, 0.975, 0.99 };;
	/*
	vector<vector<double>> zSurface;
	vector<double> nSample;
	vector<double> Probability;
	*/
};

