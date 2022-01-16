#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

const long double g = 9.8;
const long double k = 0.18;
const int m = 54;
const long double k_div_m = k / m;

inline long double dvdt(long double t, long double v){
    return g - (k_div_m * v * v);
}

int main(){
    std::ofstream fout("out3.txt");

    double deltaT = 0.1;
    double targetTime = 20;
    long double v0 = 0;

    long double currV = v0, currT = 0;
    fout << currT << '\t' << currV << '\n';
    for(int cnt = 0; cnt < (targetTime / deltaT); cnt++){
        currV = currV + deltaT * dvdt(currT, currV);
        currT += deltaT;
        fout << currT << '\t' << currV << '\n';
    }
}