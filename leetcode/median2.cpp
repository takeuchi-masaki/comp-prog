#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> a, b;
    if(nums1.size() > nums2.size()){
        a = nums2, b = nums1;
    } else {
        a = nums1, b = nums2;
    }
    int m = a.size(), n = b.size();
    // a is empty
    if(m==0){
        if(n==0){
            return 0;
        }
        int half = n>>1;
        if(n&1){
            return b[half];
        } else {
            return (b[half-1]+b[half])/2.0;
        }
    }

    int half_total = (m+n-1)>>1;
    int imin = -1, imax = m;
    // find 2 numbers if even, 1 number if odd
    int target = (m+n)&1 ? 0 : 1;
    while(imax - imin > target){
        int i = (imin + imax)>>1;
        int j = half_total - i;
        if( i<m && a[i]<b[j] ){
            imax = i;
        } else if( i>=0 && a[i]>b[j] ){
            imin = i;
        } else if(i<m && i>=0 && a[i] == b[j]) {
            return a[i];
        }
        cout << imin << ' ' << imax << endl;
    }
    int maxLeft = b[half_total-imax], minRight = b[half_total-imin];
    if(imin != -1){
        maxLeft = max(maxLeft, a[imin]);
    }
    if(imax != m){
        minRight = min(half_total-imax, a[imax]);
    }
    return (maxLeft + minRight)/2.0;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for(int&i:a) cin >> i;
    for(int&i:b) cin >> i;
    cout << fixed << setprecision(5);
    cout << findMedianSortedArrays(a,b) << endl;
}