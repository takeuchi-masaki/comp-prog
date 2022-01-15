#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

inline long double dydt(long double t, long double y){
    return std::exp(t) * std::sin(y);
}

int main(){
    std::ofstream fout("out2.txt");

    double deltaT = 0.001;
    double targetTime = 2;
    int y0 = 5;

    long double currY = y0, currT = 0;
    fout << std::setw(5) << currT << ' ' << currY << '\n';
    for(int cnt = 0; cnt < (targetTime / deltaT); cnt++){
        currY = currY + deltaT * dydt(currT, currY);
        currT += deltaT;
        if(cnt % 10 == 9){
            fout << std::setw(5) << currT << ' ' << currY << '\n';
        }
    }
}