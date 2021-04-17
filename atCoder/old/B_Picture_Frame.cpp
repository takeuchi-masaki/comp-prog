#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    for(int i = 0; i < w+2; i++){
        cout << "#";
    }
    cout << '\n';
    for(int i = 0; i < h; i++){
        cout << "#";
        for(int j = 0; j < w; j++){
            char curr;
            cin >> curr;
            cout << curr;
        }
        cout << "#\n";
    }
    for(int i = 0; i < w+2; i++){
        cout << "#";
    }
}