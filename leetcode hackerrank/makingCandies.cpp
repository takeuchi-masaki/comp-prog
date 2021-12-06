#include <bits/stdc++.h>
using namespace std;

long daysNecessary(long machines, long workers, long totalCandies){
    long rate = machines * workers;
    return (totalCandies + rate - 1) / rate;
}

void buy(long & machines, long & workers, long hired){
    if(machines >= workers){
        long hireWorkers = min(hired, machines - workers);
        workers += hireWorkers;
        hired -= hireWorkers;
    } else {
        long hireMachines = min(hired, workers - machines);
        machines += hireMachines;
        hired -= hireMachines;
    }
    if(hired&1){
        hired--;
        if(workers <= machines) workers++;
        else machines++;
    }
    hired >>= 1;
    workers += hired;
    machines += hired;
}

long minimumPasses(long machines, long workers, long price, long numCandies){
    long remainder = 0, days = 0;
    while(remainder < numCandies){
        days++;
        remainder += machines * workers;
        if(remainder >= numCandies) break;
        long necessary = daysNecessary(machines, workers, numCandies - remainder);
        long nextRemainder = remainder, nextMachines = machines, nextWorkers = workers;
        for(long hire = 1; hire < remainder / price; hire++){
            long currMachines = machines, currWorkers = workers;
            long currRemainder = remainder - (hire * price);
            buy(currMachines, currWorkers, hire);
            long currNecessary = daysNecessary(currMachines, currWorkers, numCandies - currRemainder);
            if(currNecessary < necessary){
                necessary = currNecessary;
                nextRemainder = currRemainder;
                nextMachines = currMachines;
                nextWorkers = currWorkers;
            }
        }
        remainder = nextRemainder;
        machines = nextMachines;
        workers = nextWorkers;
    }
    return days;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
}