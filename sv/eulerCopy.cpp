#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

inline long double dydt(long double t, long double y){
    long double square = y * y;
    return (square * y) - square;
}

int main(){
    std::ofstream fout("out2.txt");

    double deltaT = 0.1;
    double targetTime = 10;
    long double y0 = 0.2;

    long double currY = y0, currT = 0;
    // fout << std::setw(5) << currT << ' ' << currY << '\n';
    fout << currY << '\n';
    for(int cnt = 0; cnt < (targetTime / deltaT); cnt++){
        currY = currY + deltaT * dydt(currT, currY);
        currT += deltaT;
        fout << currY << '\n';
        // if(cnt % 10 == 9){
        //     fout << std::setw(5) << currT << ' ' << currY << '\n';
        // }
    }
}