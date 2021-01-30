// Code for unit root test taken here: http://timebird.egloos.com/4689342
// Newmat11 library from Robert Davies obtained here: http://www.robertnz.net/download.html

#include "StatisticalTest.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

#include "newmat11/newmat.h"
#include "newmat11/newmatio.h"


using namespace std;

#define WANT_MATH
#define WANT_STREAM

#ifdef use_namespace
using namespace NEWMAT;
#endif

StatisticalTest::StatisticalTest() {
	ifstream zSurface_file;
	
	switch (TestType) {
	case ADF_TEST:
		zSurface_file.open("ADF_Critical.csv");
		break;
	default:
		zSurface_file.open("ADF_Critical.csv");
	}

	while (zSurface_file.is_open()) {
		string line;
		for (int row = 0; row < 6; row++) {
			for (int col = 0; col < 8; col++) {
				if (col > 7) {
					getline(zSurface_file, line, '\n');
					zSurface[row][col] = stod(line);
				}
				else {
					getline(zSurface_file, line, ',');
					zSurface[row][col] = stod(line);
				}
			}
			zSurfacePtr[row] = zSurface[row];
		}
		zSurface_file.close();
	}

}

StatisticalTest::~StatisticalTest() {

}


ReturnMatrix StatisticalTest::OLS(Matrix& x, Matrix& y) {
	Matrix ma = (((x.t() * x).i()) * x.t()) * y;
	ma.Release();
	return ma;
}

ReturnMatrix StatisticalTest::OLSError(Matrix& x, Matrix& y, ColumnVector& beta, int df) {
	ColumnVector residuals = y + ((x * beta) * (-1));
	Real residualSumOfSquares = (residuals.t() * residuals).AsScalar();
	Real Sigma2 = residualSumOfSquares / df;
	DiagonalMatrix diag; diag << ((x.t() * x).i()) * Sigma2;

	for (int i = 1; i <= diag.Nrows(); i++) {
		diag(i) = pow(diag(i), 0.5);
	}

	residuals.Release();
	diag.Release();
	return diag;
}

void StatisticalTest::adfTest(double*x, int obs, int k, double* dfs, double* pv){
	int lags = k + 1;
	int cols = (lags - 1) + 3;
	int rows = obs - lags;

	Matrix xMat(rows, cols);
	ColumnVector yMat(rows);

	double* delta = new double[obs - 1];
	for (int i = 0; i < (obs - 1); i++) {
		delta[i] = x[i + 1] - x[i];
	}


}
