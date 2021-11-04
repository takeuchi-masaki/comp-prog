#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int sum = accumulate(a.begin(), a.end(), 0);
    if(sum&1){
        cout << "0\n";
        return 0;
    }
    for(int mask = 0; mask < (1<<n); mask++){
        vector<bool> use(n);
        for(int bit = 0; bit < n; bit++){
            if(mask>>bit&1) use[bit] = true;
        }
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++){
            if(use[i]){
                sum1 += a[i];
            } else {
                sum2 += a[i];
            }
        }
        if(sum1 == sum2){
            vector<int> l, r;
            for(int i = 0; i < n; i++){
                if(use[i]){
                    l.push_back(a[i]);
                } else {
                    r.push_back(a[i]);
                }
            }
            for(int i:l) cout << i << ' ';
            cout << '\n';
            for(int i:r) cout << i << ' ';
            cout << '\n' << '\n';
        }
    }
}