#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    s.erase(s.size()-1);
    while(s.size()>0){
        if(s.size()%2==0){
            if(s.substr(0,s.length()/2) == s.substr(s.length()/2)){
                cout << s.length();
                break;
            }
        }
        s.erase(s.size()-1);
    }
}