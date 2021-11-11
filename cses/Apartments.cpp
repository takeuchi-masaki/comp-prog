#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // applicants, apartments, maxdiff
    int n, m, k; cin >> n >> m >> k;
    vector<int> desired(n), apartment(m);
    for(int & i : desired) cin >> i;
    for(int & i : apartment) cin >> i;
    sort(desired.begin(), desired.end());
    sort(apartment.begin(), apartment.end());
    int currPerson = 0, currApt = 0, ans = 0;
    while(currPerson < n && currApt < m){
        bool bigEnough = desired[currPerson] >= apartment[currApt] - k;
        bool smallEnough = desired[currPerson] <= apartment[currApt] + k;
        if(bigEnough && smallEnough){
            ans++;
            // cout << desired[currPerson] << ' ' << apartment[currApt] << '\n';
            currPerson++, currApt++;
            continue;
        }
        if(!bigEnough) currPerson++;
        if(!smallEnough) currApt++;
    }
    cout << ans << '\n';
}