#include <iostream>
using namespace std;

int main(){
    int n,y;
    cin >> n >> y;
    // target y yen
    // n bills
    /*
        10,000 5,000 1,000
        10k 5k 1k
    */
   int max = n*10000;
   int man = -1, gosen=-1, sen=-1;
   bool found = false;
   for(int i = 0; i <= n; i++){
       for(int j = 0; j <= n-i; j++){
           int k = n-i-j;
           int money = 10000 * i + 5000 * j + 1000 * k;
           if(money == y){
               man = i;
               gosen = j;
               sen = k;
               found = true;
               break;
           }
       }
        if(found) break;
   }
   cout << man << " " << gosen << " " << sen;
}