#include <bits/stdc++.h>
using namespace std;

int xMin, yMin, xMax, yMax;
set<int> validX, validY;

void simulateX(int velX, int currX, int time){
    if(currX >= xMin && currX <= xMax) validX.insert(time);
    if(currX > xMax || velX == 0) return;
    simulateX(velX - 1, currX + velX, time + 1);
}

void simulateY(int velY, int currY, int time){
    if(currY >= yMin && currY <= yMax) {
        if((time >= *validX.rbegin()) || validX.count(time)){
            int startY = velY + time;
            int maxY = startY * (startY + 1) / 2;
            validY.insert(maxY);
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
        
        cout << xMin << ' ' << xMax << ' ' << yMin << ' ' << yMax << '\n';
    }
    
    for(int x = 0; x <= xMax; x++){
        simulateX(x, 0, 0);
    }

    for(int y = 200; y >= 0; y--){
        simulateY(y, 0, 0);
    }
    cout << *validY.rbegin() << '\n';
}