#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n),b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    const long long INF = 1E18;
    long long res = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            long long entrance = a[i], exit = b[j], dist = 0;
            for(int k = 0; k < n; k++){
                long long closer, farther, dist1=0, dist2=0;
                if( abs(entrance-a[k]) <= abs(entrance-b[k]) ){
                    closer = a[k];
                    farther = b[k];
                } else {
                    closer = b[k];
                    farther = a[k];
                }
                dist1 += abs(closer - entrance);
                dist1 += abs(farther - closer);
                dist1 += abs(exit - farther);

                dist2 += abs(farther - entrance);
                dist2 += abs(closer - farther);
                dist2 += abs(exit - closer);

                dist += min(dist1,dist2);
                // cout << abs(closer - entrance) << endl
                //     << abs(farther - closer) << endl
                //     << abs(exit - farther) << endl;
            } 
            res = min(res,dist);
        }
    }
    cout << res << endl;
    cout << endl;
}