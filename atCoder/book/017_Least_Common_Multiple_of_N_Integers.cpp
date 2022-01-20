#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b){
	if(b == 0) return a;
	return GCD(b, a % b);
}

long long LCM(long long a, long long b){
	return (a / GCD(a, b)) * b;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<long long> a(n);
    for(long long& ll : a) cin >> ll;
    
    long long ans = LCM(a[0], a[1]);
    for(int i = 2; i < n; i++){
        ans = LCM(ans, a[i]);
    }
    cout << ans << '\n';
}