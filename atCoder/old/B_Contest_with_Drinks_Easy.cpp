#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    long long sum = 0;
    for(int& i:t){
        cin>>i;
        sum+=i;
    }
    int m;
    cin >> m;
    vector<int> p(m), x(m);
    for(int i = 0; i < m; i++){
        cin >> p[i] >> x[i];
    }
    for(int i = 0; i < m; i++){
        cout << sum-t[p[i]-1]+x[i] <<'\n';
    }
}