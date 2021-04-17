#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> vs;
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        vs.push_back(s);
    }
    /*
        i,j   i+1,j
        i,j+1 i+1,j+1
    */
    int res = 0;
    for(int i = 0; i < h - 1; i++){
        for(int j = 0; j < w - 1; j++){
            int sharp = 0;
            if(vs[i][j] == '#') ++sharp;
            if(vs[i + 1][j] == '#') ++sharp;
            if(vs[i][j + 1] == '#') ++sharp;
            if(vs[i+1][j+1] == '#') ++sharp;
            if(sharp == 1 || sharp == 3) ++res;
        }
    }
    cout << res;
}

