#include <bits/stdc++.h>
using namespace std;

char bomb[51][51];
int h, w;
char search_bomb(int i, int j){
    int bombCount = 0;
    if(i-1 >= 0){
        if(j-1>=0)
            if(bomb[i-1][j-1] == '#') bombCount++;

        if(bomb[i-1][j] == '#') bombCount++;

        if(j+1<w)
            if(bomb[i-1][j+1] == '#') bombCount++;
    }

    if(j+1<w)
        if(bomb[i][j+1] == '#') bombCount++;

    if(j-1>=0)
        if(bomb[i][j-1] == '#') bombCount++;

    if(i+1 < h){
        if(j-1>=0)
            if(bomb[i+1][j-1] == '#') bombCount++;

        if(bomb[i+1][j] == '#') bombCount++;

        if(j+1<w)
            if(bomb[i+1][j+1] == '#') bombCount++; 
    }
    return (char) bombCount + '0';
}

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++){
            bomb[i][j]=s[j];
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(bomb[i][j]!='#'){
                bomb[i][j] = search_bomb(i,j);
            }
            cout << bomb[i][j];
        }
        cout << endl;
    }
}