#include <bits/stdc++.h>
using namespace std;
int n;
vector< vector<int> > grid1, grid2;

void printAll(vector< vector<int> > &grid){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void rotate90(){
    vector< vector<int> > new_grid(n, vector<int>(n));
    for(int j = n-1, ii = 0; j >= 0; j--, ii++){
        for(int i = 0, jj = 0; i < n; i++, jj++){
            new_grid[i][j] = grid1[ii][jj];
        }
    }
    // printAll(grid1);
    // cout << endl;
    // printAll(new_grid);
    // cout << endl << endl;
    grid1 = new_grid;
}

bool checkTranslation(){
    int minI = n-1, minJ = n-1;
    int minI2 = n-1, minJ2 = n-1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid1[i][j] == 1){
                minI = min(minI, i);
                minJ = min(minJ, j);
            }
            if(grid2[i][j] == 1){
                minI2 = min(minI2, i);
                minJ2 = min(minJ2, j);
            }
        }
    }
    // cout << minI << ' ' << minJ << endl;
    // cout << minI2 << ' ' << minJ2 << endl;
    vector< vector<int> > translate(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int currI = i+minI, currJ = j+minJ;
            if(currI >= n || currJ >= n){
                continue;
            }
            translate[i][j] = grid1[currI][currJ];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int comp;
            int currI = i+minI2, currJ = j+minJ2;
            if(currI >= n || currJ >= n){
                comp = 0;
            } else {
                (grid2[currI][currJ] ? comp=1 : comp=0);
            }
            if(translate[i][j] != comp){
                return false;
            }
        }
    }
    return true;
}


int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    grid1 = vector< vector<int> >(n, vector<int>(n));
    grid2 =  vector< vector<int> >(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c=='#') grid1[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c=='#') grid2[i][j] = 1;
        }
    }
    bool ok = false;
    if(checkTranslation()) ok = true;
    for(int i = 0; i < 3; i++){
        rotate90();
        if(checkTranslation()) ok = true;
    }
    cout << (ok?"Yes\n":"No\n");
}