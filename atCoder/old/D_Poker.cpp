#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int k;
    string takahashi, aoki;
    cin >> k;
    cin >> takahashi >> aoki;
    int kCount[10] = {}, tCount[10] = {}, aCount[10] = {};
    long long remaining = (k*9) - 8;
    cout << remaining << endl;
    // remaining*=remaining-1;
    for(int i = 0; i < 4; i++){
        char c = takahashi[i];
        int num = (int)c-(int)'0';
        kCount[num]++;
        tCount[num]++;
    }
    for(int i = 0; i < 4; i++){
        char c = aoki[i];
        int num = (int)c-(int)'0';
        kCount[num]++;
        aCount[num]++;
    }
    long long tSum = 0, aSum = 0;
    int count = 1;
    for(int i:tCount){
        long long ten = pow(10,i);
        tSum+=ten*count;
        count++;
    }
    count = 1;
    for(int i:aCount){
        long long ten = pow(10,i);
        aSum+=ten*count;
        count++;
    }
    long long tSum2[10] = {}, aSum2[10] = {};
    for(int i=0; i <= 9; i++){
        tSum2[i] = tSum - ((i+1)*pow(10,tCount[i])) + ((i+1)*pow(10,tCount[i]+1));
        aSum2[i] = aSum - ((i+1)*pow(10,aCount[i])) + ((i+1)*pow(10,aCount[i]+1));
        cout << tSum2[i] << " " << aSum2[i] << endl;
    }
    long double ans = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(tSum2[i] > aSum2[j]){
                long double iCount = (k-kCount[i]) / (long double) remaining;
                long double jCount = k-kCount[i];
                if(i == j) jCount--;
                jCount /= (remaining-1);
                ans+= iCount*jCount;
            }
        }
    }
    cout << setprecision(16) << ans;
}