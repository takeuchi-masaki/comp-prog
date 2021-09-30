#include <bits/stdc++.h>
using namespace std;

// (X[i], Y[i]) are coordinates of i'th point.
double polygonArea(double X[], double Y[], int n)
{
    // Initialze area
    double area = 0.0;
 
    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  // j is previous vertex to i
    }
 
    // Return absolute value
    return abs(area / 2.0);
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int d, l; cin >> d >> l;
    l*=1000; // 1l == 1000 cm^3
    double X[n], Y[n];
    for(int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
    }
    double area = polygonArea(X, Y, n); //cm^3
    cout << area << '\n';
    double max_volume = area * d;
    if(l > max_volume) {
        l = max_volume;
    }
    double ans = l/area;
    cout << ans << '\n';
}