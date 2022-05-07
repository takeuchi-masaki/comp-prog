#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pair<int,int> start1, start2, end1, end2;
    cin >> start1.first >> start1.second >> start2.first >> start2.second;
    cin >> end1.first >> end1.second >> end2.first >> end2.second;

    // euclidean distance between runners at start and end
    long double startDiff = sqrtl(powl(start1.first - start2.first, 2) + powl(start1.second - start2.second, 2));
    long double endDiff = sqrtl(powl(end1.first - end2.first, 2) + powl(end1.second - end2.second, 2));
    cout << fixed << setprecision(10) << max(startDiff, endDiff) << '\n';
}