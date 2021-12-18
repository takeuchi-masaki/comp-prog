#include <bits/stdc++.h>
using namespace std;

int xMin, yMin, xMax, yMax;
map<int, vector<int>> validX;
set<int>limit;
set<pair<int,int>> validPair;

void simulateX(int velX){
    int x = 0, time = 0, currX = velX;
    while(currX > 0){
        x += currX;
        currX--;
        time++;
        if(x >= xMin && x <= xMax){
            validX[time].push_back(velX);
        }
    }
    
    int finalDist = velX * (velX + 1) / 2;
    if(finalDist >= xMin && finalDist <= xMax){
        limit.insert(velX);
    }
}

void simulateY(int velY, int currY, int time){
    if(currY >= yMin && currY <= yMax) {
        int startY = velY + time;
        // cout << startY << ' ' << time << '\n'; 
        if(validX.count(time)){
            for(int x : validX[time]){
                validPair.insert(make_pair(x, startY));
            }
        }
        auto ub = limit.upper_bound(time);
        for(auto it = limit.begin(); it != ub; it++){
            validPair.insert(make_pair(*it, startY));
        }
    }
    if(currY + velY < yMin) return;
    simulateY(velY - 1, currY + velY, time + 1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    
    {
        string line;
        getline(cin, line);
        int find_x = line.find('x');
        int x1Begin = find_x + 2;
        int x1End = line.find('.', x1Begin);
        string x1_str = line.substr(x1Begin, x1End - x1Begin);
        xMin = stoi(x1_str);

        int x2Begin = x1End + 2;
        int x2End = line.find(',', x2Begin);
        string x2_str = line.substr(x2Begin, x2End - x2Begin);
        xMax = stoi(x2_str);

        int find_y = line.find('y');
        int y1Begin = find_y + 2;
        int y1End = line.find('.', y1Begin);
        string y1_str = line.substr(y1Begin, y1End - y1Begin);
        yMin = stoi(y1_str);

        int y2Begin = y1End + 2;
        int y2End = line.size();
        string y2_str = line.substr(y2Begin, y2End - y2Begin);
        yMax = stoi(y2_str);
        
        // cout << xMin << ' ' << xMax << ' ' << yMin << ' ' << yMax << '\n';
    }
    
    for(int x = 1; x <= xMax; x++){
        simulateX(x);
    }

    // for(auto& [key, vec] : validX){
    //     cout << key << ":\n";
    //     for(int i : vec){
    //         cout << i << ' ';
    //     }
    //     cout << "\n\n";
    // }

    for(int y = 200; y > -200; y--){
        simulateY(y, 0, 0);
    }

    // cout << '\n';
    // for(auto& [x, y] : validPair){
    //     cout << x << ' ' << y << '\n';
    // }
    cout << validPair.size() << '\n';
}