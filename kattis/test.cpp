#include <bits/stdc++.h>
using namespace std;

const double MAX_ERROR = 0.001;
double findRoot(double x, int n){
    double left = 0, right = x;
    while(right-left > MAX_ERROR){
            double mid = left + (right-left)/2.0;
            double curr = 1;
            for(int i = 0; i < n; i++){
                curr*=mid;
            }
            if(curr >= x){
                right = mid;
            } else {
                left = mid;
            }
    }
    return right;
}

int main(){
    freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << sqrt(.5) << endl;
    cout << sqrt(.5) - findRoot(.5, 2) << endl;
}