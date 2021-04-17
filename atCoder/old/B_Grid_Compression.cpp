#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    // vector<vector<char>> a(h,vector<char>(w));
    vector<string> a(h);
    for(int i = 0; i < h; i++){
        cin >> a[i];
    }
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         a[i][j] = s[i][j];
    //     }
    // }
    vector<bool> pRow(h,false), pCol(w,false);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                pRow[i] = true;
                pCol[j] = true;
            }
        }
    }
    for(int i = 0; i < h; i++){
        if(pRow[i]){
            for(int j = 0; j < w; j++){
                if(pCol[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }   
    }
}