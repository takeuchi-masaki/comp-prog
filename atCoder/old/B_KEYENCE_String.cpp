#include <bits/stdc++.h>
using namespace std;

int main(){
    // case 1: delete start
    // case 2: delete end
    // case 3: delete middle
    string s;
    cin >> s;
    string key = "keyence";
    bool ok = false;
    // if(s.substr(0,key.size()) == key) ok = true;
    // if(s.substr(s.size()-key.size()) == key) ok = true;
    if(!ok){    
        int left = 0;
        string res = "";
        while(left < key.size() && s[left] == key[left]){
            res+=s[left];
            left++;
        }
        int right = s.size()-1;
        int keyR = key.size()-1;
        string rightres = "";
        while((res+rightres).size() < key.size()
        && right >= 0 && keyR>=0 && s[right] == key[keyR]){
            rightres = s[right] + rightres;
            right--;
            keyR--;
        }
        if(res+rightres == key) ok = true;
    }
    std::cout << (ok?"YES":"NO") << endl;
}