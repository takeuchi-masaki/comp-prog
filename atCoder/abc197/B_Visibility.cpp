#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--, y--;
    vector<string> grid(h);
    for(int i = 0; i<h; i++){
        cin >> grid[i];
    }
    int res = 0;
    if(grid[x][y]=='.') res++;
    // pair<int,int> check[] = {
    //     {x,y},
    //     {x-1,y},
    //     {x+1,y},
    //     {x,y+1},
    //     {x,y-1}
    // };
    int xCopy = x-1, yCopy = y;
    while(xCopy>=0 && grid[xCopy][yCopy]=='.'){
        res++;
        xCopy--;
    }
    xCopy = x+1, yCopy = y;
    while(xCopy<h && grid[xCopy][yCopy]=='.'){
        res++;
        xCopy++;
    }
    xCopy = x, yCopy = y-1;
    while(yCopy>=0 && grid[xCopy][yCopy]=='.'){
        res++;
        yCopy--;
    }
    xCopy = x, yCopy = y+1;
    while(yCopy<w && grid[xCopy][yCopy]=='.'){
        res++;
        yCopy++;
    }
    cout << res << '\n';
}