#include <bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    UF uf(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        uf.join(a, b);
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        if(uf.sameSet(a, b)){
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}