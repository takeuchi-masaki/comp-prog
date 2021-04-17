#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for(auto& i: x){
        cin >> i;
    }
    // separate x's into n blocks
    // place pieces down costs 0 moves
    int count = 0;
    if(n < m){
        sort(x.begin(),x.end());
        vector<int> diffs(m-1);
        for(int i = 0; i < m-1; i++){
            diffs[i] = abs(x[i] - x[i+1]);
        }
        sort(diffs.begin(), diffs.end(), greater<>());
        for(int i = n-1; i < m-1; i++){
            count+=diffs[i];
        }
    } 
    cout << count;
}

