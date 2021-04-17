#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    for(auto& i:x) cin >> i;
    vector<int> copy(x);
    sort(copy.begin(),copy.end());
    int left = copy[n/2 - 1], right = copy[n/2];
    for(int i = 0; i < n; i++){
        if(x[i]<=left) {
            cout << right << endl;
        } else {
            cout << left << endl;
        }
    }
}