/*
ID: themasa1
TASK: ride
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

const int mod = 47;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b; fin >> a >> b;
    int n = a.size(), n2 = b.size();
    long long a1 = 1, b1 = 1;
    for(int i = 0; i < n; i++){
        a1*= a[i]-'A'+1;
    }
    for(int i = 0; i < n2; i++){
        b1*= b[i]-'A'+1;
    }
    a1%=mod, b1%=mod;
    fout << (a1==b1?"GO\n":"STAY\n");
    return 0;
}