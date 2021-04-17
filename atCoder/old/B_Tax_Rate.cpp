#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i < 50000; i++){
        int num = i*1.08;
        if(num == n) ans = i;
    }
    if(ans == 0){
        cout << ":(";
    } else {
        cout << ans;
    }
}