#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    long long kill = 0;
    int currMax = a.back();
    a.pop_back();
    while(!a.empty()){
        if(currMax == 0){
            cout << "1\n";
            return 0;
        }
        int curr = a.back();
        a.pop_back();
        if(curr >= currMax){
            kill += curr - currMax + 1;
            curr = currMax - 1;
        }
        currMax = curr;
    }
    cout << kill << '\n';
}