#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int parity1 = 0, parity2=0;    
    for(int i = 0; i < s.length(); i++){
        if(s[i]!='0'+(i&1)){
            parity1++;
        } else {
            parity2++;
        }
    }
    cout << min(parity1,parity2) << endl;
}