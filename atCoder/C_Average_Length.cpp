#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    vector<int> path(n);
    iota(path.begin(), path.end(), 0);
    long double total = 0;
    int iterations = 0;
    do{
        iterations++;
        long double currTotal = 0;
        for(int next = 1; next < n; next++){
            long double diffX = x[path[next-1]] - x[path[next]],
            diffY = y[path[next-1]] - y[path[next]];
            diffX*=diffX, diffY*=diffY;
            diffX+=diffY;
            currTotal += sqrtl(diffX);
        }
        total += currTotal;
    } while(next_permutation(path.begin(), path.end()));
    total /= iterations;
    cout << fixed << setprecision(10) << total << endl;
}