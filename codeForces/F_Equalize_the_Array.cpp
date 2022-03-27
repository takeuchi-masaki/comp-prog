#include <bits/stdc++.h>
using namespace std;

struct FT{
	vector<long long> bit;
	int n;
	FT(int n) : bit(n+1, 0), n(n) {}
	long long sum(int r){
		long long ret = 0;
		while(r > 0){
			ret += bit[r];
			r -= r & -r;
		}
		return ret;
	}
	
	long long sum(int l, int r){
		return sum(r) - sum(l);
	}
	
	void add(int i, int k){
		while(i < bit.size()){
			bit[i] += k;
			i += i & -i;
		}
	}
};

void solve(){
    int n; cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        m[num]++;
    }

    vector<int> frq;
    for(auto[a, b] : m){
        frq.push_back(b);
    }
    sort(frq.begin(), frq.end());
    int F = frq.size();
    
    int ans = 0;
    for(int i = 0; i < F; i++){
        ans = min(ans, frq[i] * (F - i));
    }

    cout << n - ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}