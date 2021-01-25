// AlgoTrader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StatisticalTest.h"

using namespace std;

void print2DVec(vector<vector<double>> vec);

int main()
{
    StatisticalTest ADF;
    vector<vector<double>> Test;
    Test = ADF.getZSurface();
    print2DVec(Test);
    
}

void print2DVec(vector<vector<double>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}