#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i:a) cin >> i;
    sort(a.begin(),a.end(),greater<int>());
    int x1, x2, y1, y2;
    int res = 0;
	
    cout << res << endl;
}