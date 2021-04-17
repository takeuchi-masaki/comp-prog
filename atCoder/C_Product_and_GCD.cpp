#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int lp[N+1];
vector<int> sieve(){
	vector<int> pr;
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
	return pr;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n, p; cin >> n >> p;
    if(n==1) {
        cout << p << '\n';
        return 0;
    }

    vector<int> pr = sieve();
    long long res = 1;
    vector<int> primeFactors;
    for(int i:pr){
        if(i>p) break;
        if(p%i==0) {
            primeFactors.push_back(i);
        }
    }

    map<int,int> cnt;
    for(int i:primeFactors){
        while(p%i==0){
            p/=i;
            cnt[i]++;
        }
    }
    for(auto [x,y]:cnt){
        int factorAll = y/n;
        for(int i = 0; i < factorAll; i++){
            res*=x;
        }
    }

    cout << res << '\n';
}