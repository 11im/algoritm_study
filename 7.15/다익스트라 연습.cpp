#include <iostream>
#include <utility>
#include <queue>
#include <vector>

#define INF 987654321
#define MAX 20010 //정점의 개수가 20000개

using namespace std;

int V, E, K; //정점 개수, 간선 개수, 시작점
vector<pair<int,int>> Vector[MAX]; // Vector[시작점] == <도착점, 거리>
int Distance[MAX]; //Distance[도착점] == 도착점 까지의 거리합

int Input(){
    cin >> V >> E >> K;
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c; 
        Vector[a].push_back(make_pair(b,c)); //a가 시작점 b가 도착점 c가 거리
    }
    for(int j = 1; j <= V; j++){
        Distance[j] = INF; //거리를 전부 inf로 초기화
    }
}

int Solve(){
    priority_queue<pair<int,int>> PQ; //경로 저장
    PQ.push(make_pair(0,K));
    Distance[K] = 0;

   while(!PQ.empty()){
       int current = PQ.top().second;
       int cost = -PQ.top().first;
       PQ.pop();

       for(int i = 0; i < Vector[current].size; i++){
           int next = Vector[current][i].first;
           int ncost = Vector[current][i].second;

           if(Distance[next] > cost + ncost){
               Distance[next] = cost + ncost;
               PQ.push(make_pair(-Distance[next],next)); //-로 넣어주면 별도의 설정 없이 최소 거리가 우선순위를 가지게 됨
           }
       }
   }
}