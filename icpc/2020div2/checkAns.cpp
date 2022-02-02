#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    bool ok = true;
    string s;

    ifstream fin1{"speed.out"};
    vector<string> s1;
    while(getline(fin1, s)){
        s1.push_back(move(s));
    }

    ifstream fin2{"out.txt"};
    int i = 0;
    while(getline(fin2, s)){
        if(s != s1[i++]){
            cout << "NG line " << i << endl;
            ok = false;
        }
    }
    if(ok){
        cout << "ALL CLEAR\n";
    }
}