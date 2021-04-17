#include <iostream>
using namespace std;

int main(){
    int n,a,b,res=0;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        int curr = i, sum = 0;
        while(curr>0){
            sum+=curr%10;
            if(sum>b) break;
            curr/=10;
        }
        if(sum>=a && sum <= b) res+=i;
    }
    cout << res << endl;
}