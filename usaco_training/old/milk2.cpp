/*
ID: themasa1
TASK: milk2
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;


int cnt[300005];

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n; fin >> n;

    int start = 1e9, end = 0;
    for(int i = 0; i < n; i++){
        int a, b; fin >> a >> b;
        cnt[a]++;
        cnt[b]--;
        start = min(start, a);
        end = max(end, b);
    }
    int continuous = 0, idle = 0, curr = 0;
    int currCont = 0, currIdle = 0;
    for(int i = start; i <= end; i++){
        curr+=cnt[i];
        if(curr>0){
            idle = max(idle, currIdle);
            currIdle = 0;
            currCont++;
            // continuous = max(continuous,currCont);
        } else {
            // if(i == end) break;
            continuous = max(continuous,currCont);
            currCont = 0;
            currIdle++;
            // idle = max(idle, currIdle);
        }
    }
    fout << continuous << ' ' << idle << '\n';
    return 0;
}