#include<iostream>
#include<random>
#include<iomanip>
#include<ctime>

using namespace std;
const int TRIALS = 100000;
// const int DRAWS = 22;
const int LADICA = 3, FLOWERING = 3;
const int DECKSIZE = 40;

int main(){
    srand(time(nullptr));
    for(int ACCELS = 15; ACCELS <= 20; ACCELS++){
        cout << "accels: " << ACCELS << endl;
        for(int DRAWS = 15; DRAWS <= 30; DRAWS++){
            int accels = ACCELS;
            int success = 0;
            for(int trial = 0; trial < TRIALS; trial++){
                int accel_cnt = accels, ladica_cnt = LADICA, flowering_cnt = FLOWERING;
                int curr_accel = 0, curr_ladica = 0, curr_flowering = 0;
                bool done = false;
                int draws = DRAWS, decksize = DECKSIZE;
                while(draws--){
                    int card = rand()%decksize;
                    if(card<accel_cnt){
                        curr_accel++;
                        accel_cnt--;
                    } else if(card<accel_cnt+ladica_cnt){
                        curr_ladica++;
                        ladica_cnt--;
                    } else if(card<accel_cnt+ladica_cnt+flowering_cnt){
                        curr_flowering++;
                        flowering_cnt--;
                    }
                    decksize--;
                }
                if(curr_accel>=6 && curr_ladica>=1 && curr_flowering>=1){
                    success++;
                }
            }
            cout << fixed << setprecision(2);
            // cout << "draws: " << DRAWS << endl
            //      << "successrate: " << (double)success/TRIALS << endl << endl;
            // cout << DRAWS << ": " << (double)success/TRIALS << endl;
            cout << (double)success/TRIALS << endl;
        }
        cout << endl;
    }
}