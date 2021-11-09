#include <bits/stdc++.h>
using namespace std;
int ROW, COL, n;
vector< vector<char> > grid;
vector< vector<int> > grid2;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> ROW >> COL;
    grid = vector< vector<char> >(ROW, vector<char>(COL, ' '));
    grid2 = vector< vector<int> >(ROW, vector<int>(COL, -1));
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cin >> grid[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(grid2[i][j]!=-1) continue;
            deque< pair<int,int> > q;
            q.push_back(make_pair(i,j));
                grid2[i][j] = count;
            while(q.size()){
                pair<int,int> p = q.front();
                q.pop_front();
                vector< pair<int,int> > nextCoord = {
                    {p.first-1, p.second},
                    {p.first+1, p.second},
                    {p.first, p.second-1},
                    {p.first, p.second+1}
                };
                for(pair<int,int> next:nextCoord){
                    if(next.first < 0
                    || next.second < 0
                    || next.first >= ROW
                    || next.second >= COL) continue;
                    if(grid2[next.first][next.second] != -1) continue;
                    if(grid[next.first][next.second] 
                    != grid[i][j]) continue;
                    grid2[next.first][next.second] = count;
                    q.push_back(make_pair(next.first, next.second));
                }
            }
            count++;
        }
    }

    // for(int i = 0; i < ROW; i++){
    //     for(int j = 0; j < COL; j++){
    //         cout << grid2[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cin >> n;
    while(n--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        if(grid2[r1][c1] == grid2[r2][c2]){
            cout << (grid[r1][c1]=='0'?"binary\n":"decimal\n");
        } else {
            cout << "neither\n";
        }
    }
}