#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> map;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        map.insert(make_pair(a[i],b[i]));
        map.insert(make_pair(b[i],a[i]));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int res = 0;
    
}