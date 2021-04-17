#include <iostream>
#include <string>
using namespace std;

int a,b;

int main(){
    // int a,b;
    cin >> a >> b;
    int res = 0;
    for(int i = a; i <= b; i++){
        string s = to_string(i);
        string rev = "";
        for(int j = 0; j < s.length(); j++){
            rev = s[j]+rev;
        }
        if(stoi(rev)==i){
            res++;
        }
    }
    cout << res << endl;
}