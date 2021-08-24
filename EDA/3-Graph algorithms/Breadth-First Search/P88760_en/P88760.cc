#include<iostream>
#include<vector>
#include<queue>
#include <cmath>
using namespace std;

struct stone{
    double x;
    double y;
    double r;
};

typedef pair <stone, int> travel;

bool jumpable (stone &A, stone &B, double d){
    double BigX = pow((A.x - B.x), 2);
    double BigY = pow( (A.y - B.y), 2 );
    double dist = sqrt( BigX +BigY);
    dist = dist - (A.r+B.r);
    return dist < d; 
}

int less_jumpstart(vector<stone> &V, const double &d){
    queue<travel> MyQ;
    MyQ.push({V[0], 0});
    int N = V.size();
    vector<bool> visits(N, false);
    vector<int> distance(N, -1); 
    distance[0]=0;
    stone aux;
    int ref;
    while (not MyQ.empty()){
        aux = MyQ.front().first;
        ref = MyQ.front().second;
        MyQ.pop();
        if (visits[ref] == false){
            visits[ref] = true;
            for (int i = 1; i < N; ++i){
                if ( jumpable (aux, V[i], d) && distance[i] == -1){
                    MyQ.push({V[i], i});
                    distance[i] = distance[ref] + 1;
                    if (i == N-1) return distance [i];
                }
            }
        }
    }
    return -1;
}

int main(){
    int n;
    double d;
    while (cin >> n >> d){
        vector<stone> stones(n);
        double x, y, r;
        for (int i = 0; i < n; ++i){
            cin >> x >> y >> r;
            stones[i] = {x, y, r};
        }
        int aux = less_jumpstart(stones, d);
        if (aux != -1) cout << aux << endl;
        else cout << "Xof!" << endl;
    }
}
