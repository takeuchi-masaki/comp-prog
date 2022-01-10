#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> time(m + 1);
    map<int,int> lastRead;
    for(int i = 1; i <= m; i++){
        int s; cin >> s;
        time[i] = time[i - 1] + n - 1;
        if(lastRead.count(s)){

        }
    }
}