#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        a[temp] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}