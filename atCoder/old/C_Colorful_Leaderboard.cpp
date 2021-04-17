#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int colors[9] = {};
    int sum = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp <= 399){
            colors[0]++;
        } else if(temp <= 799){
            colors[1]++;
        } else if(temp <= 1199){
            colors[2]++;
        } else if(temp <= 1599){
            colors[3]++;
        } else if(temp <= 1999){
            colors[4]++;
        } else if(temp <= 2399){
            colors[5]++;
        } else if(temp <= 2799){
            colors[6]++;
        } else if(temp <= 3199){
            colors[7]++;
        } else {
            colors[8]++;
        }
    }
    for(int i = 0; i < 8; i++){
        if(colors[i]>0){
            sum++;
        }
    }
    
    cout << max(sum,1) << " " << sum+colors[8] << endl;
}