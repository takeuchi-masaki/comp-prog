#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

inline long double dxdt(long double y){
    return y;
}

inline long double dydt(long double x){
    return -sinl(x);
}

int main(){
    std::ofstream fout("out1.txt");

    double deltaT = 0.25;
    // double targetTime = 2;
    int STEPS = 8;
    long double x0 = 0, y0 = 2;

    long double currX = x0, currY = y0, currT = 0;
    fout << currT << '\t' << currX << '\t' << currY << '\n';
    for(int cnt = 0; cnt < STEPS; cnt++){
        long double nextX = currX + deltaT * dxdt(currY);
        long double nextY = currY + deltaT * dydt(currX);        
        currT += deltaT;
        currX = nextX, currY = nextY;
        fout << currT << '\t' << currX << '\t' << currY << '\n';
    }
}