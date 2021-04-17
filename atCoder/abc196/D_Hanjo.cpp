#include <bits/stdc++.h>
using namespace std;

int h, w, a, b;
bool use[16][16];

long long dfs(int i, int j, int a, int b){
    if(a<0 || b<0) return 0;
    if(j==w) { j=0; i++; }
    if(i==h) { return 1; }
    long long res = 0;
    if(use[i][j]) return dfs(i, j+1, a, b);
    use[i][j]=true;
    res+=dfs(i, j+1, a, b-1);
    if(j+1<w && !use[i][j+1]){
        use[i][j+1]=true;
        res+=dfs(i,j+1,a-1,b);
        use[i][j+1]=false;
    }
    if(i+1<h && !use[i+1][j]){
        use[i+1][j]=true;
        res+=dfs(i,j+1,a-1,b);
        use[i+1][j]=false;
    }
    use[i][j]=false;
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> h >> w >> a >> b;
    cout << dfs(0,0,a,b) << endl;
}