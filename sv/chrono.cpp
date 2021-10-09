#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

mt19937 rng(0);

int main(){
    vector<int> deck(40);
    for(int i = 0; i < 40; i++){
        deck[i] = i;
    }
    shuffle(deck.begin(), deck.end(), rng);
    
}