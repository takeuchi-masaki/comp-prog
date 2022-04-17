#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BinaryIndexedTree {
	int N;
	vector<T> data;

	BinaryIndexedTree() = default;

	BinaryIndexedTree(int size) { init(size); }

	void init(int size) {
		N = size + 2;
		data.assign(N + 1, {});
	}

	// get sum of [0,k]
	T sum(int k) const {
		if (k < 0) return T {}; // return 0 if k < 0
		T ret {};
		for (++k; k > 0; k -= k & -k) ret += data[k];
		return ret;
	}

	// getsum of [l,r]
	inline T sum(int l, int r) const { return sum(r) - sum(l - 1); }

	// get value of k
	inline T operator[](int k) const { return sum(k) - sum(k - 1); }

	// data[k] += x
	void add(int k, T x) {
		for (++k; k < N; k += k & -k) data[k] += x;
	}

	// range add x to [l,r]
	void imos(int l, int r, T x) {
		add(l, x);
		add(r + 1, -x);
	}

	// minimize i s.t. sum(i) >= w
	int lower_bound(T w) {
		if (w <= 0) return 0;
		int x = 0;
		for (int k = 1 << __lg(N); k; k >>= 1) {
			if (x + k <= N - 1 && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x;
	}

	// minimize i s.t. sum(i) > w
	int upper_bound(T w) {
		if (w < 0) return 0;
		int x = 0;
		for (int k = 1 << __lg(N); k; k >>= 1) {
			if (x + k <= N - 1 && data[x + k] <= w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x;
	}
};

template<typename T>
struct RangeAddRangeSumBIT {
	BinaryIndexedTree<T> a, b;
	RangeAddRangeSumBIT(int N): a(N + 1), b(N + 1) {}

	// add x to [l, r)
	void add(int l, int r, T x) {
		a.add(l, x);
		a.add(r, -x);
		b.add(l, x * (1 - l));
		b.add(r, x * (r - 1));
	}

	// return sum of [l, r)
	T sum(int l, int r) {
		--r, --l;
		return a.sum(r) * r + b.sum(r) - a.sum(l) * l - b.sum(l);
	}

	T get(int idx) {
		return sum(idx, idx + 1);
	}
};


void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> change(n);

	bool parity = k & 1;
	RangeAddRangeSumBIT<int> fenwick(n);
	int curr_k = 0;
	for (int i = 0; i < n && curr_k < k; i++) {
		if ((s[i] - '0' + parity + fenwick.get(i)) % 2 == 0) {
			change[i]++;
			parity ^= 1;
			curr_k++;
			fenwick.add(i + 1, n, 1);
		}
	}

	change[n - 1] += k - curr_k;
	parity = k & 1;
	for (int i = 0; i < n; i++) {
		if (change[i] & 1) parity ^= 1;
		if ((s[i] - '0' + fenwick.get(i) + parity) % 2 == 1) {
			cout << '1';
		} else {
			cout << '0';
		}
	}
	cout << '\n';
	for (int i: change) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}