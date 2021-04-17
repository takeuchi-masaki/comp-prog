#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> b(n);
    for(auto& i:b) cin >> i;
    long long sum = b[0]+b[n-2];
    for(int i = 1; i < n; i++){
        sum+=min(b[i],b[i-1]);
    }
    cout << sum << endl;
}