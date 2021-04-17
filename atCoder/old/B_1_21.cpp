#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    a+=b;
    int num = stoi(a);
    bool sq = false;
    for(int i = 0; i <= 1000; i++){
        if(i*i == num){
            sq = true;
            break;
        }
    }
    cout << (sq?"Yes":"No");
}