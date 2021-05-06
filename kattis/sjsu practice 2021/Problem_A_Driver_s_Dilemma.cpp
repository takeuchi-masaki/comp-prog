#include <bits/stdc++.h>
using namespace std;

int main(){
    double c, x, m; cin >> c >> x >> m;
    c/=2;
    // cout << c << ' ' << x << ' ' << m << endl;
    int resSpeed = 0;
    for(int i = 0; i < 6; i++){
        int speed;
        double mpg;
        cin >> speed >> mpg;
        // cout << speed << ' ' << mpg << endl;

        double time = m/speed; // hours
        double leak = time * x; // gallons
        double fuelUse = m/mpg;

        // cout << time << ' ' << leak << ' ' << fuelUse << endl;
        if(c - leak - fuelUse < 0) continue;
        resSpeed = max(resSpeed, speed);
    }

    if(resSpeed == 0){
        cout << "NO\n";
    } else {
        cout << "YES " << resSpeed << endl;
    }
}