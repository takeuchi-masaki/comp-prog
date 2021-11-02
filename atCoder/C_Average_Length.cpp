#include <bits/stdc++.h>
using namespace std;

int n;
long double total = 0;
int iterations = 0;
vector<int> x, y;

void dfs(vector<int> & path, vector<bool> & used){
    if(path.size() != n){
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            used[i] = true;
            path.push_back(i);
            dfs(path, used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }
    int currX = x[path[0]], currY = y[path[0]];
    for(int idx = 1; idx < n; idx++){
        int nextX = x[path[idx]], nextY = y[path[idx]];
        long double currDist = sqrtl( (currX-nextX)*(currX-nextX) + (currY-nextY)*(currY-nextY) );
        total += currDist;
        currX = nextX, currY = nextY;
    }
    iterations++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    x = y = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    vector<int> path;
    vector<bool> used(n, false);
    dfs(path, used);

    total /= iterations;
    cout << fixed << setprecision(10) << total << endl;
}