#include <iostream>
using namespace std;

int main(){
    int x;
    scanf("%d",&x);

    // jump length = i
    int sum = 0;
    int count = 1;
    while(sum<x){
        sum+=count++;
    }
    cout << count-1 << endl;
}