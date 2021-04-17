#include <bits/stdc++.h>
using namespace std;

int main(){
    const long long INF = 1E9+7;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < m; i++){
        cin >> c[i] >> d[i];
    }
    for(int i = 0; i < n; i++){
        long long closest_distance = INF;
        int closest_index = 99;
        for(int j = 0; j < m; j++){
            long long disX = abs(a[i]-c[j]);
            long long disY = abs(b[i]-d[j]);
            if(disX+disY < closest_distance){
                closest_distance = disX + disY;
                closest_index = j;
            }
        }
        cout << closest_index+1 << endl;
    }
}