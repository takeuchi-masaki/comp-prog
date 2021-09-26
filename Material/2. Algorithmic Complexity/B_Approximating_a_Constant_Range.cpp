#include <iostream>
#include <vector>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int &i:a){
        cin >> i;
    }
    int start = 0, maxRange = 0;
    for(int end = 0; end < n; end++){
        while( start<end && abs(a[start]-a[end])>1 ){
            // cout << a[start] << ' ' << a[end] << endl;
            start++;
        }
        cout << start << ' ' << end << endl;
        maxRange = max(maxRange, end-start+1);
    }
    cout << maxRange << endl;
}