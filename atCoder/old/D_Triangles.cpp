#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> l(n);
    for(int& i:l)cin>>i;
    sort(l.begin(),l.end());
    long long res = 0;
    int largest = l[n-1];
    for(int i = 0; i < n-2; i++){
        for(int j = n-2; j > i; j--){
            int r = lower_bound(l.begin(), l.end(), l[i]+l[j])-l.begin();
            int add = r-(j+1);
            if(add<0) break;
            res+=add;
        }
    }
    cout << res << '\n';
}