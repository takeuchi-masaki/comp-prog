#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double getRoot(int square){
    double l = 0.1, r = 2000*2000; 
    for(int i = 1; i <= 100; i++){
        double m = (l+r) / 2;
        if(m*m <= square){
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    double sum = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int diffX = abs(x[i]-x[j]);
            int diffY = abs(y[i]-y[j]);
            sum += getRoot(diffX*diffX + diffY*diffY);
        }
    }
    cout << fixed << setprecision(10) << sum/(n/2.0);
}