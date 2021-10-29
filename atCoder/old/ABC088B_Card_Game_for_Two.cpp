#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int&i:a)cin>>i;
    sort(a.begin(), a.end(), greater<int>());
    int asum = 0, bsum = 0;
    for(int i = 0; i < n; i++){
        if(i&1){
            bsum += a[i];
        } else {
            asum += a[i];
        }
    }
    cout << asum-bsum << '\n';
}