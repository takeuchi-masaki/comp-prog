#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0;
    cin >> sum;
    for(int i = 0; i < n - 1; i++){
        int add;
        cin >> add;
        sum += add - 1;
    }
    cout << sum << '\n';
}