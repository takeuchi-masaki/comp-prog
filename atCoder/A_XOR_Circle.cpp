#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<int,int> a;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        a[temp]++;
    }
    if(a.size()==1 && a.begin()->first == 0){
        cout << "Yes\n";
        return 0;
    }

    bool ok = false;
    if(n%3==0 && a.size()<=3){
        n/=3;
        if(a.size()==3){
            bool n3 = true;
            int nums[3];
            int cnt = 0;
            for(auto [x,y]:a){
                nums[cnt++] = x;
                if(y != n) {
                    n3 = false;
                    break;
                }
            }
            if(n3){
                if( (nums[0] ^ nums[2]) == nums[1]
                &&  (nums[1] ^ nums[0]) == nums[2]
                &&  (nums[2] ^ nums[1]) == nums[0]){
                    ok = true;
                }
            }
        }
        else if(a.size()==2){
            int cnt = 0;
            for(auto [x,y]:a){
                if( cnt==0 && (x!=0 || y!=n) ){
                    break;
                }
                if( cnt==1 && y==n*2 ){
                    ok = true;
                }
                cnt++;
            }
        }
    }
    cout << (ok?"Yes":"No") << '\n';
}