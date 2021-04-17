#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string d = "dream";
    string d2 = "er";
    string e = "erase";
    int pos = 0;
    char prev = '0';
    string res = "";
    while(res.length() < s.length()){
        pos = res.length();
        string sub;
        if(pos+5 > s.length()){
            sub = "";
        } else {
            sub = s.substr(pos, 5);
        }
        if(sub == d){
            res+=d;
            prev = 'd';
        } else if(sub == e){
            res+=e;
            prev = 'e';
        } else if(prev != '0'){
            if(prev == 'd'){
                if(pos+2 <= s.length() && s.substr(pos,2) == d2) {
                    res+=d2;
                } else {
                    break;
                }
            } else {
                if(s[pos] == 'r') {
                    res+="r";
                } else {
                    break;
                }
            }
            prev = '0';
        } else {
            break;
        }
    }
    cout << (res == s?"YES":"NO");
}