/*
ID: themasa1
TASK: transform
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;
ofstream fout ("transform.out");
ifstream fin ("transform.in"); 

int n;
vector<vector<bool>> before, after;

bool check(vector<vector<bool>>& cmp){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cmp[i][j]!=after[i][j]) return false;
        }
    }
    return true;
}

vector<vector<bool>> rotate(vector<vector<bool>>& v){
    vector<vector<bool>> ret(n, vector<bool>(n));
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         int i2 = n-1-j, j2 = i;
    //         ret[i][j] = v[i2][j2];
    //         // fout << ret[i][j];
    //     }
    //     // fout << endl;
    // }
    for(int j = 0; j < n; j++){
        for(int i = n-1; i >= 0; i--){
            ret[j][n-1-i] = v[i][j];
        }
    }
    return ret;
}

vector<vector<bool>> reflect(){
    vector<vector<bool>> ret(n, vector<bool>(n));
    for(int i = 0; i < n; i++){
        int cntj = n-1;
        for(int j = 0; j < n; j++){
            ret[i][j] = before[i][cntj];
            // fout << ret[i][j];
            cntj--;
        }
        // fout << endl;
    }
    return ret;
}

int solve(){
    vector<vector<bool>> ans = vector<vector<bool>>(before);
    for(int i = 1; i<=3; i++){
        ans = rotate(ans);
        if(check(ans)) return i;
    }

    ans = reflect();
    if(check(ans)) return 4;

    for(int i = 0; i < 3; i++){
        ans = rotate(ans);
        if(check(ans)) return 5;
    }
    if(check(before)){ return 6; }
    return 7;
}

int main() {
    
    fin >> n;
    before = after = vector<vector<bool>>(n,vector<bool>(n));
    for(int i = 0; i < n; i++){
        string s; fin >> s;
        for(int j = 0; j < n; j++){
            if(s[j]=='@') before[i][j] = true;
        }
    }
    for(int i = 0; i < n; i++){
        string s; fin >> s;
        for(int j = 0; j < n; j++){
            if(s[j]=='@') after[i][j] = true;
        }
    }
    fout << solve() << '\n';
    return 0;
}