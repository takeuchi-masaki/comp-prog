#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> balls(n+1,1); // 1 index
    vector<bool> possible(n+1, false);
    possible[1]=true;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        balls[x]--;
        balls[y]++;
        if(possible[x]){
            possible[y]=true;
            if(balls[x]==0){
                possible[x]=false;
            }
        }
    }
    int res = 0;
    for(bool b:possible) if(b) res++;
    cout << res << '\n';
}