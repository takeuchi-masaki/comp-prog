#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int& i:a)cin>>i;
    for(int& i:b)cin>>i;
    long long above = 0, below = 0;
    vector<int> abv;
    int change = 0;
    for(int i = 0; i < n; i++){
        if(a[i]<b[i]){
            below+=b[i]-a[i];
            change++;
        } else if(a[i]>b[i]){
            int extra = a[i]-b[i];
            above+=extra;
            abv.push_back(extra);
        }
    }
    if(above<below) {
        cout << "-1\n";
        return 0;
    }
    sort(abv.begin(), abv.end(), greater<int>());
    int cnt = 0;
    while(below>0){
        below-=abv[cnt++];
    }
    cout << change+cnt << '\n';
    return 0;
}