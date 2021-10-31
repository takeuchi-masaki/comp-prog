#include <bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<bool> > & user){
    int n = user.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(user[i][j]){
                cout << 'Y';
            } else {
                cout << 'N';
            }
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector< vector<bool> > user(n, vector<bool>(n, false));
    for(int i = 0; i < q; i++){
        int command; cin >> command;
        int a, b; cin >> a;
        a--;
        if(command == 1){
            // a follows b
            cin >> b;
            b--;
            user[a][b] = true;
            // cout << command << ' ' << a << ' ' << b << '\n' << '\n';

        } else if(command == 2){
            // a followback
            for(int i = 0; i < n; i++){
                if(user[i][a]){
                    user[a][i] = true;
                    // cout << a << ' ' << i << '\n';
                }
            }

        } else if(command == 3){
            // printGrid(user);
            // a follow-follow
            vector<int> follow;
            for(int i = 0; i < n; i++){
                if(i == a) continue;
                if(user[a][i]){
                    // cout << a << ' ' << i << endl;
                    for(int j = 0; j < n; j++){
                        if(j == a || j == i) continue;
                        if(user[i][j]){
                            follow.push_back(j);
                        }
                    }
                }
            }
            for(int i:follow) user[a][i] = true;
        }
    }
    printGrid(user);
}