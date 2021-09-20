#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int CASES = 1000000;
bool DEBUG = false;
const char* decklistfile = "decklist.txt";
vector<int> deck;
unordered_map<int, string> cardName;
unordered_set<string> wisps, draw;
string ladica = "Ladica, Verdant Claw";
string wolf = "Deepwood Wolf";
string windf = "Wind Fairy";
string resolve = "Heroic Resolve";

int gotLadica=0, success=0, cumulative=0;

void importList(){
    freopen(decklistfile, "r", stdin);
    int currDecksize = 0;
    string line;
    getline(cin, line);
    int numLines = stoi(line);
    while(numLines--){
        getline(cin, line);
        int count = line[line.length()-1]-'0';
        string add = line.substr(0, line.length()-3);
        // cout << add << endl;
        // cout << count << endl;
        for(int i = currDecksize; i < currDecksize+count; i++){
            cardName.insert(make_pair(i, add));
        }
        currDecksize+=count;
    }
}

void define(){
    wisps.insert("Fairy Slugger");
    wisps.insert("Aria, Miasma Fairy");
    wisps.insert("Cryptid Keeper");
    wisps.insert("Sen, Stormclaw Cat");
    draw.insert("Tree of Wonders");
    draw.insert("Life Banquet");
}

int main(){
    importList();
    define();
    srand(time(nullptr));

    for(int i = 0; i < 40; i++){
        deck.push_back(i);
    }
    for(int test = 0; test < CASES; test++){
        random_shuffle(deck.begin(), deck.end());
        int wolfcnt = 0, windfcnt = 0, wisp = 0, extraDraws = 0, lad = 0, resolvecnt = 0;
        for(int i = 0; i < 9; i++){
            int card = deck[i];
            string name = cardName[card];
            if(DEBUG) cout << name << endl;
            if(draw.count(name)){
                extraDraws++;
                if(name=="Life Banquet") extraDraws++;
            } else if(wisps.count(name)){
                wisp++;
            } else if(name==ladica){
                lad++;
            } else if(name==wolf){
                wolfcnt++;
            } else if(name==windf){
                windfcnt++;
            } else if(name==resolve){
                resolvecnt++;
            }
        }
        for(int i = 9; i < 9+extraDraws; i++){
            int card = deck[i];
            string name = cardName[card];
            if(DEBUG) cout << name << endl;
            if(wisps.count(name)){
                wisp++;
            } else if(name==ladica){
                lad++;
            } else if(name==wolf){
                wolfcnt++;
            } else if(name==windf){
                windfcnt++;
            } else if(name==resolve){
                resolvecnt++;
            }
        }
        int zero = wisp+lad+resolvecnt;
        if(wisp>2) wisp = 2;
        if(windfcnt>=wisp){
            zero+=2*wisp;
            zero+=1*(windfcnt-wisp);
            // wisp-=windfcnt;
        } else {
            zero+=2*windfcnt;
            wisp-=windfcnt;
            wolfcnt = min(wisp, wolfcnt);
            zero+=wisp*wolfcnt;
        }
        if(lad>0){
            gotLadica++;
        }
        if(lad>0 && zero>=6){
            success++;
        }
        cumulative+=zero;
    }
    cout << setprecision(2) << fixed 
         << "gotLadica: " << gotLadica << endl
         << "success: " << (double)success/CASES << endl
         << "avg zero: " << (double)cumulative/CASES << endl;

    return 0;
}