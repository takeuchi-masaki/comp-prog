#include <bits/stdc++.h>
using namespace std;

int main(){
    double W,H,x,y;
    cin >> W >> H >> x >> y;
    double area = H*W/2.0;
    int res = 0;
    double slope = H/W, slope2=-W/H;
    double slopeXY = y/x;
    if(x+x==W && y+y==H)res = 1;
    printf("%.12f %d\n",area,res);
}