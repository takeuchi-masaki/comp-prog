#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
    }
    int k;
    cin >> k;
    vector<int> c(k),d(k);
    for(int i = 0; i < k; i++){
        cin >> c[i] >> d[i];
    }
    int k2 = 1 << k; // 2^k
    int max = 0;
    for(int bit = 0; bit < k2; bit++){
        vector<bool> ball(n);
        for(int i = 0; i < k; i++){
            int index;
            if(bit & (1 << i)){
                index = d[i];
            } else {
                index = c[i];
            }
            ball[index] = 1;
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            if(ball[a[i]] && ball[b[i]]){
                count++;
            }
        }
        if(max < count) max = count;
    }
    cout << max;
}

