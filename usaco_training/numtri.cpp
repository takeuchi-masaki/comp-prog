/*
ID: themasa1
TASK: numtri
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
int r;
vector< vector<int> > triangle;
int squares[1001][1001];

int main() {
    freopen("numtri.in","r",stdin); freopen("numtri.out","w",stdout);
    cin >> r;
    triangle = vector< vector<int> >(r);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < i+1; j++){
            int num; cin >> num;
            triangle[i].push_back(num);
        }
    }
    squares[0][0] = triangle[0][0];
    for(int i = 1; i < r; i++){
        for(int j = 0; j < i+1; j++){
            vector< pair<int, int> > check = {
                {i-1, j-1},
                {i-1, j},
            };
            for(pair<int, int> p:check){
                if(p.second < 0) continue;
                if(p.second >= i) continue;
                squares[i][j] = 
                    max(squares[i][j], squares[p.first][p.second] + triangle[i][j]);
            }
        }
    }
    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < i+1; j++){
    //         cout << squares[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for(int i = 0; i < r; i++){
        ans = max(ans, squares[r-1][i]);
    }
    cout << ans << '\n';
    return 0;
}