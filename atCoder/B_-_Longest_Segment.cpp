#include <bits/stdc++.h>
using namespace std;

template<class T>
int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x = 0, T y = 0): x(x), y(y) {}
	bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
	bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
	P operator+(P p) const { return P(x + p.x, y + p.y); }
	P operator-(P p) const { return P(x - p.x, y - p.y); }
	P operator*(T d) const { return P(x * d, y * d); }
	P operator/(T d) const { return P(x / d, y / d); }
	T dot(P p) const { return x * p.x + y * p.y; }
	T cross(P p) const { return x * p.y - y * p.x; }
	T cross(P a, P b) const { return (a - *this).cross(b - *this); }
	T dist2() const { return x * x + y * y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this / dist(); } // makes dist()=1
	P perp() const { return P(-y, x); }		  // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")";
	}
};

typedef Point<long long> P;
vector<P> convexHull(vector<P> pts) {
	if (pts.size() <= 1) return pts;
	sort(pts.begin(), pts.end());
	vector<P> h(pts.size() + 1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end()))
		for (P p: pts) {
			while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
			h[t++] = p;
		}
	return { h.begin(), h.begin() + t - (t == 2 && h[0] == h[1]) };
}

array<P, 2> hullDiameter(vector<P> S) {
	int n = S.size(), j = n < 2 ? 0 : 1;
	pair<long long, array<P, 2>> res({ 0, { S[0], S[0] } });
	for (int i = 0; i < j; i++)
		for (;; j = (j + 1) % n) {
			res = max(res, { (S[i] - S[j]).dist2(), { S[i], S[j] } });
			if ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0)
				break;
		}
	return res.second;
}

void solve() {
	int n;
	cin >> n;
	vector<P> pts(n);
	for (auto& p: pts) {
		cin >> p.x >> p.y;
	}
	vector<P> hull = convexHull(pts);
	array<P, 2> d = hullDiameter(hull);
	cout << fixed << setprecision(10);
	cout << (d[0] - d[1]).dist() << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}