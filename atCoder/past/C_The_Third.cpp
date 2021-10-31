#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a(6);
    for(int&i:a)cin >> i;
    sort(a.begin(), a.end());
    cout << a[3] << endl;
}