#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, m; cin >> n >> m;
    vector< vector<int> > grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    vector< vector<int> > minleft, minright, maxleft, maxright;
    minleft = minright = maxleft = maxright = vector< vector<int> >(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        minleft[i][0] = grid[i][0];
        maxleft[i][0] = grid[i][0];
        for(int j = 1; j < m; j++){
            minleft[i][j] = min(minleft[i][j-1], grid[i][j]);
            maxleft[i][j] = max(maxleft[i][j-1], grid[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        minright[i][m-1] = grid[i][m-1];
        maxright[i][m-1] = grid[i][m-1];
        for(int j = m-2; j >= 0; j--){
            minright[i][j] = min(minright[i][j+1], grid[i][j]);
            maxright[i][j] = max(maxright[i][j+1], grid[i][j]);
        }
    }
    vector< vector<int> > valid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            // cout << minleft[i][j] << ' ' << maxright[i][j+1] << '\n';
            // cout << minright[i][j+1] << ' ' << maxleft[i][j] << '\n' << '\n';
            if(minleft[i][j] > maxright[i][j+1]){
                valid[i][j] += 1;
            }
            if(minright[i][j+1] > maxleft[i][j]){
                valid[i][j] += 2;
            }
        }
        // cout << '\n';
    }

    vector<int> color(n);
    int countR = 0, countB = 0, countRB = 0;
    int ans = -1;
    for(int j = 0; j < m; j++){
        bool ok = true;
        for(int i = 0; i < n && ok; i++){
            if(valid[i][j] == 0){
                ok = false;
            } else color[i] = valid[i][j];
        }
        if(ok) {
            countR = 0, countB = 0;
            for(int i = 0; i < n; i++){
                if(color[i]&1){
                    countR++;
                }
                if(color[i]>>1&1){
                    countB++;
                }
            }
            if(countR == 0 || countB == 0) ok = false;
            int lmin=-1, lmax=-1, rmin=-1, rmax=-1;
            for(int i = 0; i < n; i++){
                if(color[i]==1){
                    if(lmin == -1){
                        lmin = minleft[i][j];
                        rmax = maxright[i][j+1];
                    } else {
                        lmin = min(lmin, minleft[i][j]);
                        rmax = max(rmax, maxright[i][j+1]);
                    }
                } else {
                    if(rmin == -1){
                        rmin = minright[i][j+1];
                        lmax = maxleft[i][j];
                    } else {
                        rmin = min(rmin, minright[i][j+1]);
                        lmax = max(lmax, maxleft[i][j]);
                    }
                }
            }
            if(lmin <= rmax || rmin <= lmax){
                ok = false;
            }
            if(ok) {
                ans = j;
                break;
            }
        }
    }
    if(ans == -1){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string s = "";
        countR = max(0, countR-countRB);
        countB = max(0, countB-countRB);
        for(int j = 0; j < n; j++){
            if(color[j] == 1){
                s.push_back('R');
            } else if(color[j] == 2){
                s.push_back('B');
            } else {
                if(countR == 0){
                    s.push_back('R');
                    countR++;
                } else if(countB == 0){
                    s.push_back('B');
                    countB++;
                } else {
                    s.push_back('R');
                }
            }
        }
        cout << s << ' ' << ans+1 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}