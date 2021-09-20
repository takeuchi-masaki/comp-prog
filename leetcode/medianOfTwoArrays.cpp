#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> arr1, arr2;
    arr1 = nums1;
    arr2 = nums2;
    if(nums1.size() > nums2.size()){
        arr1 = nums2;
        arr2 = nums1;
    }
    int m = arr1.size(), n = arr2.size();
    if(m==0){
        if(n==0){
            return 0;
        }
        int half = n>>1;
        if(n&1){
            return arr2[half];
        } else {
            return (arr2[half]+arr2[half-1])/2.0;
        }
    }
    int half = (m+n+1)>>1;
    int imin = 0, imax = m;
    while(imin <= imax){
        int i = (imin + imax)>>1;
        int j = half-i;
        if(i>0 && arr1[i-1] > arr2[j]){
            imax-=1;
        } else if(i<m && arr1[i] < arr2[j-1]){
            imin+=1;
        } else{
            int maxLeft, minRight;
            if(i==0){
                maxLeft = arr2[j-1];
            } else if(j==0){
                maxLeft = arr1[i-1];
            } else {
                maxLeft = max(arr1[i-1], arr2[j-1]);
            }
            if(i==m){
                minRight = arr2[j];
            } else if(j==n){
                minRight = arr1[i];
            } else {
                minRight = min(arr1[i], arr2[j]);
            }
            if( (m+n)&1 ){
                // cout << "odd"<< endl;
                return maxLeft;
            } else {
                // cout << "even" << endl;
                return (maxLeft + minRight)/2.0;
            }
        }
    }
    return 0;
}



int main(){
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for(int&i : nums1) cin >> i;
    for(int&i : nums2) cin >> i;
    cout << fixed << setprecision(5);
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}