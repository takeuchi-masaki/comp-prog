#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m, c;
    cin >> n >> m >> c;
    int count = 0;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        int currSum = c;
        for(int j = 0; j < m; j++){
            currSum += a[i][j]*b[j];
        }
        if(currSum > 0) count++;
    }
    cout << count;
}