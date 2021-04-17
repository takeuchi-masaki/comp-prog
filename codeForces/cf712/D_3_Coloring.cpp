#include <bits/stdc++.h>
using namespace std;
int n;
int cnt1, cnt2;
bool grid[101][101];
vector<pair<int,int>> rem1, rem2;

void solve(){
    int a; cin >> a;
    int b, i, j;


    cout << b << ' ' << i << ' ' << j << endl;
}

int main(){
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    int tt = n*n;
    cnt1 = cnt2 = tt/2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; i++){
            if((i+j)&1){
                rem1.push_back(make_pair(i,j));
            } else {
                rem2.push_back(make_pair(i,j));
            }
        }
    }
    if(tt&1) cnt1++;
    for(int i = 0; i < tt; i++){
        solve();
    }
}