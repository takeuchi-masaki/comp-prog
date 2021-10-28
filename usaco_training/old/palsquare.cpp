/*
ID: themasa1
TASK: palsquare
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;
ofstream fout ("palsquare.out");
ifstream fin ("palsquare.in");

string convert(int i, int base){
    string res;
    int mult = 1;
    while(i>mult*base){
        mult*=base;
    }
    // fout << "mult: " << mult << '\n';
    while(mult>0){
        int curr = 0;
        while(i >= mult){
            i-=mult;
            curr++;
        }
        // fout << curr << '\n';
        char add;
        if(curr<=9){
            add = curr+'0';
        } else {
            curr-=10;
            add = curr+'A';
        }
        res.push_back(add);
        mult/=base;
    }
    return res;
}

int main() {
    int b; fin >> b;
    int numMin = 1, numMax = 300;
    // int numMin = 4, numMax = 4;
    for(int i = numMin; i<=numMax; i++){
        int square = i*i;
        string baseB = convert(i, b);
        string squareB = convert(square, b);
        // int converted = i;
        string copy = squareB;
        reverse(copy.begin(), copy.end());
        bool end = false;
        for(int j = 0; j < copy.size(); j++){
            if(copy[j]!=squareB[j]) {
                end = true;
                break;
            }
        }
        if(end) continue;
        fout << baseB << ' ' << squareB << '\n';
    }
    
    return 0;
}