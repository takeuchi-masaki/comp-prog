#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(auto& i:p) cin >> i;
    long double res = 0.0;
    deque<double> dq;
    for(int i = 0; i < k; i++){
        double ev = (p[i]+1)/2.0;
        dq.push_back(ev);
        res+=ev;
    }
    int index = k;
    long double curr = res;
    while(index<n){
        curr-=dq.front();
        dq.pop_front();
        double ev = (p[index]+1)/2.0;
        curr+=ev;
        dq.push_back(ev);
        res = max(res,curr);
        index++;
    }
    cout << setprecision(12) << fixed << res << endl;
}