/*
ID: themasa1
TASK: barn1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("barn1.in");
ofstream fout ("barn1.out");

int m, s, c;

int main() {
    fin >> m >> s >> c;
    if(m >= c){
        fout << c << endl;
        return 0;
    }
    set<int> occ; // occupied
    for(int i = 0; i < c; i++){
        int temp; fin >> temp;
        occ.insert(temp);
    }
    int prev = -1;
    priority_queue<int> pq;
    for(int i : occ){
        if(prev == -1){
            prev = i;
            continue;
        }
        int diff = i-prev-1;
        pq.push(diff);
        prev = i;
    }
    int low = *occ.begin();
    auto it = occ.end();
    it--;
    int high = *it;
    int res = high-low+1;
    for(int i = 0; i < m-1; i++){
        int large = pq.top();
        pq.pop();
        res-=large;
    }
    fout << res << '\n';
    return 0;
}