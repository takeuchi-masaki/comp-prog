#include <bits/stdc++.h>
using namespace std;
bool filled[3][3];


bool checkWin(){
    for(int i = 0; i < 3; i++){
        if(filled[i][0] && filled[i][1] && filled[i][2]) return true;
    }
    for(int i = 0; i < 3; i++){
        if(filled[0][i] && filled[1][i] && filled[2][i]) return true;
    }
    if(filled[0][0] && filled[1][1] && filled[2][2]) return true;
    if(filled[2][0] && filled[1][1] && filled[0][2]) return true;

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    int bingo[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> bingo[i][j];
        }
    }
    cin >> n;
    vector<int> b(n);
    for(int i = 0 ; i < n; i++) cin >> b[i];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < n; k++){
                if(bingo[i][j] == b[k]) filled[i][j] = true;
            }
        }
    }
    cout << (checkWin()? "Yes": "No");
}