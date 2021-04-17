#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int letter[26] = {};
    for(int i = 0; i < s.length(); i++){
        letter[(int)s[i]-(int)'a']++;
    }
    bool ok = true;
    for(int i:letter){
        if(i&1){
            ok = false;
            break;
        }
    }
    cout << (ok?"Yes":"No") << endl;
}