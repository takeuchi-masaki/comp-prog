#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    int res = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            double num = ((double)y[j]-y[i])/((double)x[j]-x[i]);
            if(num >= -1 && num <= 1){
                res++;
            }
        }
    }
    cout << res << '\n';
}