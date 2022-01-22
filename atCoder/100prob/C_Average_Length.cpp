#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0; 
long double sum = 0.0l;
vector<int> x, y;

void dfs(vector<int>& path, vector<bool>& visited){
    if(path.size() < n){
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            visited[i] = true;
            path.push_back(i);

            dfs(path, visited);

            visited[i] = false;
            path.pop_back();
        }
        return;
    }
    
    for(int i = 1; i < n; i++){
        int currTown = path[i - 1];
        int nextTown = path[i];
        long double xDiff = x[currTown] - x[nextTown];
        xDiff *= xDiff;
        long double yDiff = y[currTown] - y[nextTown];
        yDiff *= yDiff;
        sum += sqrtl(xDiff + yDiff);
    }
    cnt++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    x.resize(n), y.resize(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    
    vector<int> path;
    vector<bool> visited(n);
    dfs(path, visited);

    cout << fixed << setprecision(10) << sum / cnt << '\n';
}