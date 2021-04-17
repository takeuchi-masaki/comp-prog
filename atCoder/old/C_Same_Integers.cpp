#include <iostream>
// #include <cmath>
using namespace std;

int main(){
    int a[3] = {};
    cin >> a[0] >> a[1] >> a[2];
    int target = max(a[0],max(a[1],a[2]));
    int count = 0;
    for(int i = 0; i < 3; i++){
        while(a[i]+2<=target){
            a[i]+=2;
            count++;
        }
    }
    int targetCount = 0;
    for(int i = 0; i < 3; i++){
        if(a[i]==target) targetCount++;
    }
    switch (targetCount)
    {
    case 1: count++;
        break;
    case 2: count+=2;
    default:
        break;
    }
    cout << count << endl;
}