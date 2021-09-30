#include <bits/stdc++.h>
using namespace std;

struct coworker {
    long long currAnnoy, increment;
    coworker(long long annoy, long long incr){
        currAnnoy = annoy;
        increment = incr;
    }
};

auto compare = [](coworker a, coworker b){
    return (a.currAnnoy + a.increment) > (b.currAnnoy + b.increment);
};

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h, c; // help, coworkers
    cin >> h >> c;
    long long maxAnnoy = 0;
    priority_queue< coworker, vector<coworker>, decltype(compare) > pq(compare);
    for(int i = 0; i < c; i++){
        long long a, d; // annoy, increase
        cin >> a >> d;
        maxAnnoy = max(maxAnnoy, a);
        pq.push( coworker(a, d) );
    }
    // priority queue of structs, sorted by next min annoyance
    // keep track of max annoy

    for(int i = 0; i < h; i++){
        coworker c = pq.top();
        pq.pop();
        c.currAnnoy += c.increment;
        maxAnnoy = max(maxAnnoy, c.currAnnoy);
        pq.push(c);
    }

    cout << maxAnnoy << endl;

    return 0;
}