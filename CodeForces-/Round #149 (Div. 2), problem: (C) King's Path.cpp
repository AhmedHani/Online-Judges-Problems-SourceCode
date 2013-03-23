#include <iostream>
#include <map>
#include <utility>
#include <queue>
using namespace std;

const int INF=1000000;
int x0, y0, x1, y1, n, r, a, b;
typedef pair<int , int> P;
map<P,int> Paths;           
queue<P> Q;
int main(){//freopen("Trojan.txt", "r", stdin);
    
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> r >> a >> b;
        for(int j = a; j <= b; j++){
            Paths[P(r,j)] = INF;
        }
    }
    Q.push(P(x0,y0));
    Paths[P(x0,y0)] = 0;
    while(!Q.empty()){
        P q = Q.front();
        Q.pop();
        for(int i = -1 ; i <= 1; i++){
            for(int j = -1 ; j <= 1; j++){
                if(Paths.count( P(q.first+i , q.second+j) ) == 1 && Paths[P(q.first + i , q.second + j)] == INF){
                    Paths[P(q.first + i , q.second + j)] = Paths[q] + 1;
                    Q.push(P(q.first + i , q.second + j));
                }
            }
        }
    }
    if(Paths[P(x1,y1)] == INF) Paths[P(x1,y1)] = -1;
    cout << Paths[P(x1 ,y1)];
    
    return 0;
}
