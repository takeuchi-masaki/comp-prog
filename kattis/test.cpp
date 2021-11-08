#include <bits/stdc++.h>
using namespace std;

int binary_search(int key, vector<int> & a) {
    int left = 0, right = (int)a.size() - 1; // 配列 a の左端と右端
    while (right >= left) {
        int mid = left + (right - left) / 2; // 区間の真ん中
        if (a[mid] == key) return mid;
        else if (a[mid] > key) right = mid - 1;
        else if (a[mid] < key) left = mid + 1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
}