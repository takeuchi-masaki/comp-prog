/*
ID: themasa1
TASK: friday
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int years; fin >> years;
    long long start = 1900, end = start+years-1;
    vector<int> dayCnt(7);
    vector<int> daysInMonth(12+1, 31);
    daysInMonth[9] = 30;
    daysInMonth[4] = 30;
    daysInMonth[6] = 30;
    daysInMonth[11] = 30;
    daysInMonth[2] = 28;

    int dayOfWeek = 2;
    for(int year = start; year <= end; year++){
        bool leap = false;
        if( (year%1000)==0 ){
            leap = true;
        } else if( (year%100)==0 ){
            // leap = false;
        } else if ( (year%4)==0 ) {
            leap = true; 
        }
        for(int month = 1; month<=12; month++){
            int maxDays = daysInMonth[month];
            if(leap && month == 2){
                maxDays++;
            }
            for(int day = 1; day <= maxDays; day++){
                if(day == 13){
                    dayCnt[dayOfWeek]++;
                }
                dayOfWeek++;
                if(dayOfWeek == 7) dayOfWeek-=7;
            }
        }
    }
    for(int i = 0; i < 7; i++){
        fout << dayCnt[i];
        if(i==6) {
            fout << endl;
        } else {
            fout << ' ';
        }
    }
    return 0;
}