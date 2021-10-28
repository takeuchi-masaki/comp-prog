/*
ID: themasa1
TASK: milk
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("milk.in");
ofstream fout ("milk.out");
int n, m;


int main() {
    fin >> n >> m; // n milk per day
    vector<pair<int,int>> farmers(m);
    for(int i = 0; i < m; i++){ // m farmers
        fin >> farmers[i].first >> farmers[i].second;
    }
    sort(farmers.begin(), farmers.end());
    long long res = 0, num = 0;
    while(n>0){
        // fout << farmers[num].first << ' ' << farmers[num].second << '\n';
        if(n<=farmers[num].second){
            res += (long long)n*farmers[num].first;
            break;
        }
        res += (long long)farmers[num].first * farmers[num].second;
        n -= farmers[num].second;
        num++;
    }
    fout << res << '\n';
    return 0;
}