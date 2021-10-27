/*
ID: themasa1
TASK: pprime
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
long long a, b;
int palMin, palMax;
vector<long long> ans;

bool checkPrime(long long num){
    if(num <= 1) return false;
    if(num <= 3) return true;
    if(num%2 == 0) return false;
    for(long long i = 3; i*i <= num; i+=2){
        if(num%i == 0) return false;
    }
    return true;
}

void findPalLen(long long aa, long long bb){
    palMin = palMax = 0;
    while(aa>0){
        aa/=10;
        palMin++;
    }
    while(bb>0){
        bb/=10;
        palMax++;
    }
}

void genOddPalindromes(int palLen){
    int half_max = 1;
    for(int i = 0; i < palLen/2; i++){
        half_max*=10;
    }
    for(int start = 0; start <= 9; start++){
        for(int num = 0; num < half_max; num++){
            if(num%10 == 0) continue;
            string half = to_string(num);
            if(half.size() < palLen/2){
                string zero = "";
                for(int i = 0; i < (palLen/2 - half.size()); i++){
                    zero.push_back('0');
                }
                half = zero + half;
            }
            string other_half = half;
            reverse(other_half.begin(), other_half.end());
            other_half.push_back(start+'0');
            other_half += half;
            long long palindrome_num = stoll(other_half);
            if( palindrome_num > b || palindrome_num < a ) continue;
            if(checkPrime(palindrome_num)){
                ans.push_back(palindrome_num);
            }
        }
    }
}

int main() {
    freopen("pprime.in","r",stdin); freopen("pprime.out","w",stdout);
    cin >> a >> b;
    findPalLen(a, b);
    if(palMin <= 2){
        vector<int> primes = {5, 7, 11};
        for(int i:primes){
            if(i < a || i > b) continue;
            ans.push_back(i);
        }
        palMin=3;
    }
    if(palMin%2 == 0) palMin++;
    for(int palLen = palMin; palLen <= palMax; palLen+=2){
        genOddPalindromes(palLen);
    }
    sort(ans.begin(), ans.end());
    for(long long i:ans){
        cout << i << '\n';
    }
    return 0;
}