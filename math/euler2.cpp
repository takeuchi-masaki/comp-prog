#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

inline long double dydt(long double t, long double y){
    long double yy = y * y;
    return yy - (yy * y);
}

int main(){
    std::ofstream fout("out2.txt");

    double deltaT = 0.1;
    double targetTime = 10;
    long double y0 = 0.2;

    long double currY = y0, currT = 0;
    fout << "0\t" << currY << '\n';
    for(int cnt = 0; cnt < (targetTime / deltaT); cnt++){
        currY = currY + deltaT * dydt(currT, currY);
        currT += deltaT;
        fout << currT << '\t' << currY << '\n';
    }
}