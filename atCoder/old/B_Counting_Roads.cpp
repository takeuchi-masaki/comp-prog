#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> city(n+1);
    for(int i = 0; i < m; i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        city[temp1]++;
        city[temp2]++;
    }
    for(int i = 1; i <= n; i++){
        cout << city[i] << '\n';
    }
}