#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(3*n);
        for(int i = 0; i < 3*n; i++){
            cin >> a[i];
        }
        int res = 0;
        do{
            int sum = 0;
            for(int i = 0; i < n; i++){
                int index = 3*i;
                int num = a[index] + a[index+1] + a[index+2];
                int minVal = min(a[index],min(a[index+1],a[index+2]));
                int maxVal = max(a[index], max(a[index+1],a[index+2]));
                num-=(minVal+maxVal);
                sum+=num;
            }
            res = max(res,sum);
        } while(next_permutation(a.begin(),a.end()));
        cout << res << endl;
    }
}