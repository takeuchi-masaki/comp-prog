#include <bits/stdc++.h>
using namespace std;

const string pea = "pea soup";
const string pancakes = "pancakes";

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    getline(cin, s);
    int n = stoi(s);
    bool ok = false;
    while(n--){
        bool havePea = false, havePancake = false;
        getline(cin, s);
        int k = stoi(s);
        getline(cin, s);
        string restName = s;
        while(k--){
            getline(cin, s);
            if(s == pea) havePea = true;
            if(s == pancakes) havePancake = true;
        }
        if(havePea && havePancake) {
            ok = true;
            cout << restName << '\n';
            break;
        }
    }
    if(!ok) cout << "Anywhere is fine I guess\n";
}