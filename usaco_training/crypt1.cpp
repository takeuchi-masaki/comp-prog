/*
ID: themasa1
TASK: crypt1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("crypt1.in");
ofstream fout ("crypt1.out");

int n;
bool a[10];

bool check(int num){
    string ii = to_string(num);
    for(int index = 0; index < ii.length(); index++){
        int num = ii[index]-'0';
        if(!a[num]) {
            return false;
        }
    }
    return true;
}

int main() {
    fin >> n;
    for(int i = 0; i < n; i++){
        int temp; fin >> temp;
        a[temp] = true;
    }
    int cnt = 0;
    for(int i = 111; i<=999; i++){
        if(!check(i)) continue;
        for(int j = 11; j <= 99; j++){
            if(!check(j)) continue;
            if(i*j>9999) continue;
            int j10 = j/10, j1 = j%10;
            if(i*j10>999 || i*j1>999) continue;
            if(!check(i*j)) continue;
            if(!check(i*j10) || !check(i*j1)) continue;
            cnt++;
        }
    }
    fout << cnt << '\n';
    return 0;
}