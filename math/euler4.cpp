#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

inline long double dydt(long double t, long double y){
    return 2*y;
}

int main(){
    std::ofstream fout("out4.txt");

    double deltaT = 0.1;
    double targetTime = 0.5;
    long double y0 = 1;

    long double currY = y0, currT = 0;
    fout << currT << '\t' << currY << '\n';
    for(int cnt = 0; cnt < (targetTime / deltaT); cnt++){
        currY = currY + deltaT * dydt(currT, currY);
        currT += deltaT;
        fout << currT << '\t' << currY << '\n';
    }
}