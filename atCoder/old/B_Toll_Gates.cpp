#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    unordered_set<int> set;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        set.insert(temp);
    }
    int toll = 0;
    for(int i = x; i < n; i++){
        if(set.count(i)) toll++;
    }
    int toll2 = 0;
    for(int i = 0; i < x; i++){
        if(set.count(i)) toll2++;
    }
    cout << min(toll, toll2) << endl;
}