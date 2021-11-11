#include <bits/stdc++.h>
using namespace std;

bool badDiagDownRight(int i, int j, vector<int> & q){
    i++, j++;
    while(i < 8 && j < 8){
        if(q[i] == j) return true;
        i++, j++;
    }
    return false;
}

bool badDiagDownLeft(int i, int j, vector<int> & q){
    i++, j--;
    while(i < 8 && j >= 0){
        if(q[i] == j) return true;
        i++, j--;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<string> board(8);
    for(string & s : board) cin >> s;
    vector<int> q(8);
    iota(q.begin(), q.end(), 0);
    int ans = 0;
    do{
        bool ok = true;
        for(int i = 0; i < 8 && ok; i++){
            if(board[i][q[i]] == '*') ok = false;
        }
        for(int i = 0; i < 8 && ok; i++){
            if(badDiagDownLeft(i, q[i], q) 
            || badDiagDownRight(i, q[i], q)) ok = false;
        }
        if(ok) ans++;
    } while(next_permutation(q.begin(), q.end()));
    cout << ans << '\n';
}