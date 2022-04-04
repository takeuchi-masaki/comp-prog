#include <bits/stdc++.h>
using namespace std;

/**
 *  0 0 1 2
 * 
 *  2 t
 *  2 1
 *  s 1
 * 
 *  
 * 
 * */

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int sx, sy, tx, ty; 
    cin >> sx >> sy >> tx >> ty;
    string path = "";
    int currX = sx, currY = sy;
    while(currY < ty) {
        currY++;    
        path.push_back('U');
    }
    while(currX < tx) {
        currX++;
        path.push_back('R');
    }
    while(currY > sy){
        currY--;
        path.push_back('D');
    }
    while(currX > sx){
        currX--;
        path.push_back('L');
    }
    
    currX--;
    path.push_back('L');
    while(currY < ty + 1){
        currY++;
        path.push_back('U');
    }
    while(currX < tx){
        currX++;
        path.push_back('R');
    }
    currY--;
    path.push_back('D');

    currX++;
    path.push_back('R');
    while(currY > sy - 1){
        currY--;
        path.push_back('D');
    }
    while(currX > sx){
        currX--;
        path.push_back('L');
    }
    currY++;
    path.push_back('U');

    cout << path << '\n';
}