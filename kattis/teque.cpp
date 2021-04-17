#include <bits/stdc++.h>
using namespace std;
const int MAX =  4*1e6;
int tq[MAX];
int start = MAX/2, end = start, curr = start;

void get(int x){
    cout << tq[x+start] << '\n';
}

int main(){
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> cmds(n);
    int cntGet = 0, cntpb = 0, cntpf = 0, cntpm = 0;
    for(int i = 0; i < n; i++){
        string command; int x;
        cin >> command >> x;
        pair<int,int> p;
        switch(command.size()){
            case 3: p.first=0;
                cntGet++;
                break;
            case 9: p.first=1; 
                cntpb++;
                break;
            case 10: p.first=2; 
                cntpf++;
                break;
            case 11: p.first=3; 
                cntpm++;
                break;
        }
        p.second=x;
        cmds[i]=p;
    }
    for(int i = 0; i < n; i++){
        pair<int,int> p = cmds[i];
        switch(p.first){
            case 0: get(p.second); break;
            case 1: 
                break;
            case 2: 
                break;
            case 3: 
                break;
        }
    }
}