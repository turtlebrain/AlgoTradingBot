#include "StatisticalTest.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

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
			vector<double> col_val;
			for (int col = 0; col < 8; col++) {
				if (col > 7) {
					getline(zSurface_file, line, '\n');
					col_val.push_back(stod(line));
				}
				else {
					getline(zSurface_file, line, ',');
					col_val.push_back(stod(line));
				}
			}
			zSurface.push_back(col_val);
		}
		zSurface_file.close();
	}
}

StatisticalTest::~StatisticalTest() {

}