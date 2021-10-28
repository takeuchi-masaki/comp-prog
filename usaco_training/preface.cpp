/*
ID: themasa1
TASK: preface
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  0 I 1
 *  1 V 5
 *  2 X 10
 *  3 L 50
 *  4 C 100
 *  5 D 500
 *  6 M 1000
 */
vector<int> numeral_count(7);

void addNumeral(int one, int five, int ten, int number){
    if(number == 0) return;
    switch(number){
        case 1: numeral_count[one]++; break;
        case 2: numeral_count[one]+=2; break;
        case 3: numeral_count[one]+=3; break;
        case 4: numeral_count[one]++; 
                numeral_count[five]++; break;
        case 5: numeral_count[five]++; break;
        case 6: numeral_count[one]++;
                numeral_count[five]++; break;
        case 7: numeral_count[five]++; 
                numeral_count[one]+=2; break;
        case 8: numeral_count[five]++;
                numeral_count[one]+=3; break;
        case 9: numeral_count[one]++;
                numeral_count[ten]++; break;
        default: break;
    }
}

int main() {
    freopen("preface.in","r",stdin); freopen("preface.out","w",stdout);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        addNumeral(0, 1, 2, i%10);
        addNumeral(2, 3, 4, (i/10)%10);
        addNumeral(4, 5, 6, (i/100)%10);
        addNumeral(6, 7, 8, (i/1000)%10);
    }
    vector<char> numerals = {
      'I', 'V', 'X', 'L', 'C', 'D', 'M'
    };
    for(int i = 0; i < 7; i++){
        if(!numeral_count[i]) continue;
        cout << numerals[i] << ' ' << numeral_count[i] << '\n';
    }
    
    return 0;
}