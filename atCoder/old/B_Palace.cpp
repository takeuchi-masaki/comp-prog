#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t,a;
    cin >> n >> t >> a;
    vector<int> h(n);
    for(int& i:h) cin >> i;
    double minDiff = 1E9;
    int res = -1;
    for(int i = 0; i < n; i++){
        double temp = t-h[i]*0.006;
        double diff = abs(temp-a);
        if(diff<minDiff){
            minDiff = diff;
            res = i+1;
        }
    }
    cout << res << endl;
}