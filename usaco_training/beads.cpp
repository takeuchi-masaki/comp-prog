/*
ID: themasa1
TASK: beads
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

struct seg{
    int length, rw, lw;
    seg(int size, int rightW, int leftW){
        length = size;
        rw = rightW;
        lw = leftW;
    }
};

int n, res = 0;
string s;
vector<bool> checked(351, false);
vector<seg> lengths;

void dfs(int start){
    char target = s[start], opp;
    if(target == 'r') opp = 'b';
    else opp = 'r';

    int index = start, len = 0, lenW = 0;
    while(true){
        if(checked[index] || s[index]==opp) break;
        if(s[index]==target) {
            len += lenW+1; 
            lenW = 0; 
            checked[index] = true;
        } else {
            lenW++;
        }
        index++;
        if(index==n) index = 0;
    }
    int rightW = lenW;
    
    index = start-1, lenW = 0;
    if(index<0) index = n-1;
    while(true){
        if(checked[index] || s[index]==opp) break;
        if(s[index]==target) {
            len += lenW+1; 
            lenW = 0; 
            checked[index] = true;
        } else {
            lenW++;
        }
        index--;
        if(index<0) index = n-1;
    }
    int leftW = lenW;

    lengths.push_back( seg(len, rightW, leftW) );
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    fin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i]=='w') continue;
        if(checked[i]) continue;
        dfs(i);
    }
    if( lengths.size()<=2 ) {
        fout << n << '\n';
        return 0;
    }

    for(int i = 0; i < lengths.size(); i++){
        seg curr = lengths[i];
        int nextIndex = i+1, prevIndex = i-1;
        if(nextIndex==lengths.size()) nextIndex = 0;
        if(prevIndex<0) prevIndex = lengths.size()-1;
        seg next = lengths[nextIndex];
        seg prev = lengths[prevIndex];
        int curr1 = curr.lw+curr.length+curr.rw + next.length+next.rw;
        int curr2 = curr.lw+curr.length+curr.rw + prev.length+prev.lw;
        // cout << curr1 << ' ' << curr2 << '\n';
        res = max(res, max(curr1, curr2));
    }
    
    fout << res << '\n';
    return 0;
}