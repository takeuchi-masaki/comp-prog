#include <bits/stdc++.h>
using namespace std;

// m km away
// t liters
long double a, b, c, d, m, t;

bool ok(long double mid){
    long double time = m/mid;
    long double necLiters = 0, vel = mid;
    necLiters += d*vel;

    vel *= mid;
    necLiters += c*vel;

    vel *= mid;
    necLiters += b*vel;
    
    vel *= mid;
    necLiters += a*vel;

    if(time*necLiters > t) return false;
    return true;
}

int main(){
    freopen("speed.in","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cout << fixed << setprecision(2);
    while(cin >> a >> b >> c >> d >> m >> t){
        // cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << m << ' ' << t << endl;
        long double low = 0, high = 1000;
        while(high-low > 0.01){
            long double mid = low + (high-low)/2;
            if( ok(mid) ){
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << low << endl;
    }
    // cout << "end\n";
}