#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

inline long double dydt(long double v){
    return v;
}

inline long double dvdt(long double v, long double y){
    return (-4*y - v)/2;
}

int main(){
    std::ofstream fout("out2.txt");

    long double deltaT = 0.01;
    long double targetTime = 30;

    long double y0 = 2, v0 = 0;

    long double currY = y0, currV = v0, currT = 0;
    fout << currT << '\t' << currY << '\t' << currV <<'\n';
    for(int cnt = 0; cnt < (targetTime / deltaT); cnt++){
        long double nextY = currY + deltaT * dydt(currV);
        long double nextV = currV + deltaT * dvdt(currV, currY);
        currT += deltaT;
        currV = nextV, currY = nextY;
        fout << currT << '\t' << currY << '\t' << currV <<'\n';
    }
}