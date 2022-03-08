#include <bits/stdc++.h>
using namespace std;

long double getArea(vector<pair<long double, long double>>& pts){
    int n = pts.size();
    long double area = 0.0L;
    int j = n - 1;
    for (int i = 0; i < n; i++){
        area += (pts[j].first + pts[i].first) * (pts[j].second - pts[i].second);
        j = i;
    }
    return abs(area / 2.0);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> points(n);
    for(auto& [x, y] : points) cin >> x >> y;
    pair<int, int> door = points[0];
    vector<long double> dist(n), prefix(n + 1);
    for(int i = 0; i < n-1; i++){
        dist[i] = powl(points[i].first - points[i+1].first, 2);
        dist[i] += powl(points[i].second - points[i+1].second, 2);
        dist[i] = sqrtl(dist[i]);
        prefix[i + 1] = prefix[i] + dist[i];
    }
    dist[n-1] = powl(points[n - 1].first - points[n - 1+1].first, 2);
    dist[n-1] += powl(points[n - 1].second - points[n - 1+1].second, 2);
    dist[n-1] = sqrtl(dist[n - 1]);
    prefix[n - 1 + 1] = prefix[n - 1] + dist[n - 1];

    vector<pair<long double, long double>> pts_ld(n);
    for(int i = 0; i < n; i++) {
        pts_ld[i].first = points[i].first;
        pts_ld[i].second = points[i].second;
    }
    long double totalArea = getArea(pts_ld);
    // long double halfArea = totalArea / 2;
    // cout << totalArea << '\n';

    // binary search on circumference
    pair<long double, long double> ans;
    long double l = 0, r = prefix.back();
    int cnt = 0;
    while(r - l > 1e-10 && cnt++ < 200){
        long double mid = l + (r - l)/2;
        int d = 0;
        for(int i = 1; i <= n; i++){
            if(prefix[i] >= mid){
                d = i - 1;
                break;
            }
        }
        // cout << d << '\n';

        long double diff = mid - prefix[d];
        long double ratio = diff / dist[d];
        pair<long double, long double> add_point = {
            points[d].first + (points[d+1].first - points[d].first) * ratio,
            points[d].second + (points[d+1].second - points[d].second) * ratio
        };

        vector<pair<long double, long double>> poly1, poly2;
        for(int pt = 0; pt < d+1; pt++){
            poly1.push_back(points[pt]);
        }
        poly1.push_back(add_point);

        // poly2.push_back(add_point);
        // for(int pt = d+1; pt < n; pt++){
        //     poly2.push_back(points[pt]);
        // }
        // poly2.push_back(points[0]);

        // long double a1 = getArea(poly1), a2 = getArea(poly2);
        long double a1 = getArea(poly1);
        // cout << a1 << ' ' << a2 << '\n';
        if(2*a1 <= totalArea){
            l = mid;
        } else {
            r = mid;
        }
        ans = move(add_point);
        // cout << ans.first << ' ' << ans.second << '\n';
    }
    cout << fixed << setprecision(10);
    cout << ans.first << ' ' << ans.second << '\n';
}