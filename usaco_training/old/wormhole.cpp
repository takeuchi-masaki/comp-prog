/*
ID: themasa1
TASK: wormhole
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("wormhole.in");
ofstream fout ("wormhole.out");

const int MAX = 12;

int N;
int X[MAX+1], Y[MAX+1];
int partner[MAX+1];
int next_right[MAX+1];

bool check(){
    // for(int i = 1; i <= N; i++){
    //     fout << i << ':' << partner[i] << " ";
    // }
    // fout << endl;
    for(int start = 1; start <= N; start++){
        int pos = partner[next_right[start]];
        for(int i = 0; i < N; i++){
            pos = partner[next_right[pos]];
            if(pos==0) break;
        }
        if(pos!=0) return true;
    }
    return false;
}

int solve(){
    int res = 0, i = 1;
    for(i; i<=N; i++){
        if(partner[i]==0) break;
    }

    if(i>N){
        if(check()){
            return 1;
        }
        return 0;
    }
    
    for(int j = i+1; j<=N; j++){
        if(partner[j]==0) {
            partner[i] = j;
            partner[j] = i;
            res += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return res;
}

int main() {
    fin >> N;
    for(int i = 1; i <= N; i++){
        fin >> X[i] >> Y[i];
    }

    // find next right portals
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if( Y[i] == Y[j] && X[i] < X[j] ){
                if( next_right[i]==0 || X[j] < X[next_right[i]] ) {
                    next_right[i] = j;
                }
            }
        }
    }

    fout << solve() << '\n';
    
    return 0;
}