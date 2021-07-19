//7.20 2-2 https://www.acmicpc.net/problem/1504

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define endl "\n"
#define MAX 810
#define INF 987654321
using namespace std;


int N, E, A, B, ANS;
vector<pair<int,int>> Vector[MAX];
int Distance[MAX];

void Input(){
    cin >> N >> E;
    for(int i = 0; i < E; i++){
        int a, b, c; cin >> a >> b >> c; //점 a, b 거리 c
        Vector[a].push_back(make_pair(b,c));
        Vector[b].push_back(make_pair(a,c)); //두 거리가 서로 같으니까
    }
    cin >> A >> B;
}

void Dijkstra(int start){
    priority_queue<pair<int,int>> PQ;
    PQ.push(make_pair(0, start));
    Distance[start] = 0;

    while(!PQ.empty()){
        int current = PQ.top().second;
        int cost = -PQ.top().first;

        for(int i = 0; i < Vector[current].size(); i++){
            int next = Vector[current][i].first;
            int ncost = Vector[current][i].second;
            if(Distance[next] > cost + ncost){
                Distance[next] = cost + ncost;
                PQ.push(make_pair(-Distance[next], next));
            }
        }
    }
}

void Solve(){
    int routeA, routeB;
    bool flagA, flagB;
    flagA = flagB= true;
    
    for(int i = 1; i <= N; i ++) Distance[i] = INF;//초기화
    Dijkstra(N); // 다익스트라 실행
    
    routeA = Distance[A]; // 시작 - A
    routeB = Distance[B]; // 시작 - B

    if(routeA == INF){
        flagA = false;
    }

    if(routeB == INF){
        flagB = false;
    }

    for(int i = 1; i <= N; i++) Distance[i] = INF;
    Dijkstra(A);//A에서 다익스트라 : A,B사이 거리만 구하면 되니까
    
    if(flagA == true){
        routeA = routeA + Distance[B]; // 시작 - A - B
    }
    if(flagB == true){
        routeB = routeB + Distance[B]; // 시작 - B - A
    }


    for(int i = 1; i <= N; i++) Distance[i] = INF;
    Dijkstra(A); //A에서 다익 : 시작 - B - A - 도착
    if(flagB == true){
        routeB = routeB + Distance[N];
    }

    for(int i = 1; i <= N; i++) Distance[i] = INF;
    Dijkstra(B); //B에서 다익 : 시작 - A - B - 도착
    if(flagA == true){
        routeA = routeA + Distance[N];
    }

    if(flagA == false && flagB == false) ANS = -1;
    else {
        if(routeA > routeB) ANS = routeB;
        else ANS = routeA;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    cout << ANS << endl;
    return 0;
}