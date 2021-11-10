#include <bits/stdc++.h>
using namespace std;

vector<int> arr = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

int lower(int key) {
    int ok = arr.size();
    int ng = -1;
    while( abs(ok-ng) > 1 ){
        int mid = (ok + ng)/2;
        if( arr[mid] >= key ) ok = mid;
        else ng = mid;
    }
    return ok;
}

int upper(int key) {
    int ok = arr.size();
    int ng = -1;
    while( abs(ok-ng) > 1 ){
        int mid = (ok + ng)/2;
        if( arr[mid] > key ) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << lower(910) << ' ' << upper(910) << '\n';
    cout << lower_bound(arr.begin(), arr.end(), 51) - arr.begin() << ' ';
    cout << upper_bound(arr.begin(), arr.end(), 51) - arr.begin() << '\n';
}