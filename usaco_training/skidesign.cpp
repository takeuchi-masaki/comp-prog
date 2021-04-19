/*
ID: themasa1
TASK: skidesign
LANG: C++14
*/
// #include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin ("skidesign.in");
ofstream fout ("skidesign.out");

int main() {
    int n; fin >> n;
    vector<int> h(n);
    for(int&i:h)fin>>i;
    sort(h.begin(), h.end());
    int minh = h[0], maxh = h[n-1];
    int res = 0;
    // auto it = upper_bound(h.begin(),h.end(),minh);
    // fout << it-h.begin() << ' ' << *it << '\n';
    int cnt = 0;
    while(maxh-minh>17){
        // if(cnt++>10) break;
        // fout << minh << ' ' << maxh << ' ' << maxh-minh << '\n';
        auto nextMin = upper_bound(h.begin(), h.end(), minh);
        int nextMinH = *nextMin;
        auto nextMax = lower_bound(h.begin(), h.end(), maxh)--;
        nextMax--;
        int nextMaxH = *nextMax;
        // fout << nextMinH << ' ' << nextMaxH << '\n';
        int lower = (nextMin - h.begin())*(nextMinH-minh);
        int upper = (h.end() - nextMax - 1)*(maxh-nextMaxH);
        // fout << lower << ' ' << upper <<  '\n';
        if(lower<=upper){
            res+=lower*lower;
            auto it = h.begin();
            for(it; it != nextMin; it++){
                *it = nextMinH;
            }
        } else {
            res+=upper*upper;
            auto it = nextMax++;
            for(it; it!=h.end(); it++){
                *it = nextMaxH;
            }
        }
        minh = h[0], maxh = h[n-1];
    }

    // while(maxh-minh>17){
    //     auto nextMin = upper_bound(h.begin(),h.end(), minh);
    //     int nextMinNum = *nextMin;
    //     int lowDiff = (nextMinNum - minh) * (nextMin-h.begin());
    //     auto nextMax = lower_bound(h.begin(),h.end(), maxh)--;
    //     int nextMaxNum = *nextMax;
    //     int highDiff = (maxh - nextMaxNum) * (h.end() - nextMax - 1);
    //     if(lowDiff <= highDiff){
    //         res+=lowDiff * lowDiff;
    //         auto it = h.begin();
    //         for(it; it!=nextMin; it++){
    //             *it = nextMinNum;
    //         }
    //     } else {
    //         res+=highDiff*highDiff;
    //         auto it = nextMax++;
    //         for(it; it!=h.end(); it++){
    //             *it = nextMaxNum;
    //         }
    //     }
    //     minh = h[0], maxh = h[n-1];
    // }
    fout << res << '\n';
    return 0;
}