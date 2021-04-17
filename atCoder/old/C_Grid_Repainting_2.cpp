#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> s(51);

bool checkAdj(int i, int j){
    if(i-1>=0){
        if(s[i-1][j] == '#') return true;
    }
    if(i+1<=h-1){
        if(s[i+1][j] == '#') return true;
    }
    if(j-1>=0){
        if(s[i][j-1] == '#') return true;
    }
    if(j+1<=w-1){
        if(s[i][j+1] == '#') return true;
    }
    return false;
}

int main(){

    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }
    // for every square on the grid, check if an adjacent square contains a #
    bool ok = true;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                if(!checkAdj(i,j)){
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) break;
    }
    cout << (ok?"Yes":"No") << endl;
}