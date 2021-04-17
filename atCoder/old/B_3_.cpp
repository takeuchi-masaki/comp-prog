#include <bits/stdc++.h>
using namespace std;

void win(int i){
    char c='A';
    c+=i;
    cout << c << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<string> s(3);
    for(int i = 0; i < 3; i++){
        cin >> s[i];
    }
    int index[3]={0, -1, -1};
    int next = 0;
    while(true){
        if(index[next]==s[next].size()){
            win(next);
            return 0;
        }
        next = s[next][index[next]]-'a';
        index[next]++;
    }
}