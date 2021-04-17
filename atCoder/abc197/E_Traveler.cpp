#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> cnt(n, vector<int>(n+1));
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<bool> seen(n+1);
    vector<int> left(n+1, -1), right(n+1, -1);
    for(int i = 0; i < n; i++){
        right[a[i]]=i;
        if(!seen[a[i]]){
            seen[a[i]]=true;
            left[a[i]]=i;
        }
    }
    
}