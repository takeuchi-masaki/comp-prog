#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, y; cin >> n >> x >> y;
    x--, y--;
    vector<int> distCount(n + 1);
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int dist =  min(j - i, 
                            min(abs(x - i) + abs(y - j), 
                                abs(y - i) + abs(x - j)) + 1);
            distCount[dist]++;
        }
    }
    for(int i = 1; i < n; i++){
        cout << distCount[i] << '\n';
    }
}