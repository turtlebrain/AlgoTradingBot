#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class StatisticalTest
{
public:
	StatisticalTest();
	~StatisticalTest();

	enum eTEST { ADF_TEST, T_TEST, CHI_SQUARE_TEST }; //Need to add more 
	eTEST TestType;

	vector<vector<double>> getZSurface() { return zSurface; }
	void adfTest(double* x, int obs, int k, double* dfs, double* pv);

private:
	vector<vector<double>> zSurface;
	vector<double> nSample;
	vector<double> Probability;
};

