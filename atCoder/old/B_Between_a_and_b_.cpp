#include <iostream>

using namespace std;
long long get(long long n, long long x){
    long long count = n/x + 1;
    if(n == -1) count = 0;
    return count;
}

int main(){
    long long a, b, x;
    cin >> a >> b >> x;
    long long count = get(b, x) - get(a-1,x);
    cout << count;
}