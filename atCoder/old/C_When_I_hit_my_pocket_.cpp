#include <iostream>
using namespace std;

int main(){
    long long k, a, b;
    cin >> k >> a >> b;
    long long res;
    if((a+2)>=b || k < a){
        res = k+1;
    } else {
        k-=a+1;
        res=b;
        if(k&1){
            k--;
            res++;
        }
        res+=(k/2)*(b-a);
    }
    cout << res << endl;
}