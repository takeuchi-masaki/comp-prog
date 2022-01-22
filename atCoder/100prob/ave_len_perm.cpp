#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    vector<int> path(n);
    iota(path.begin(), path.end(), 0);

    long double sum = 0;
    int cnt = 0;
    do{
        for(int i = 1; i < n; i++){
            long double xDiff = x[path[i - 1]] - x[path[i]];
            xDiff *= xDiff;
            long double yDiff = y[path[i - 1]] - y[path[i]];
            yDiff *= yDiff;
            sum += sqrtl(xDiff + yDiff);
        }
        cnt++;
    } while(next_permutation(path.begin(), path.end()));
    cout << fixed << setprecision(10) << sum / cnt << '\n';
}