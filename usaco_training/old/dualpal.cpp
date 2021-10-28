/*
ID: themasa1
TASK: dualpal
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;
ofstream fout ("dualpal.out");
ifstream fin ("dualpal.in");

string convert(int i, int base){
    string res = "";
    int mult = 1;
    while(i>mult*base){
        mult*=base;
    }
    // fout << "mult: " << mult << '\n';
    while(mult>0){
        int curr = 0;
        while(i >= mult){
            i-=mult;
            curr++;
        }
        // fout << curr << '\n';
        char add;
        if(curr<=9){
            add = curr+'0';
        } else {
            curr-=10;
            add = curr+'A';
        }
        res.push_back(add);
        mult/=base;
    }
    return res;
}

int main() {
    int n, s;
    fin >> n >> s;
    vector<long long> possible;
    for(int i = s+1; i<s*100; i++){
        int palcnt = 0;
        for(int base = 2; base<=10; base++){
            if(palcnt==2) break;
            string num = convert(i, base);
            string copy = num;
            reverse(copy.begin(), copy.end());
            bool ok = true;
            for(int j = 0; j < num.size(); j++){
                if(num[j]!=copy[j]){
                    ok = false; break;
                }
            }
            if(!ok) continue;
            palcnt++;
        }
        if(palcnt == 2) possible.push_back(i);
        if(possible.size() == n) {
            break;
        }
    }
    for(int i = 0; i < min(n, (int)possible.size()); i++){
        fout << possible[i] << '\n';
    }
    return 0;
}