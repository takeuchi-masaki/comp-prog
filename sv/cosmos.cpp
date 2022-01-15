#include <fstream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    const int T = 1e6;
    int success = 0;
    for(int t = 0; t < T; t++){
        int storm = 1, ppOrDmg = 2, etc = 7;
        for(int cnt = 0; cnt < 6; cnt++){
            int total = storm + ppOrDmg + etc;
            int roll = rand() % total;
            if(roll >= storm + ppOrDmg){
                etc--;
            } else if(roll == 0 && storm){
                storm--;
            } else {
                ppOrDmg--;
            }
        }
        if(!storm && ppOrDmg <= 1) success++;
    }
    ofstream fout{"out.txt"};
    fout << (long double)success / T << '\n';
}