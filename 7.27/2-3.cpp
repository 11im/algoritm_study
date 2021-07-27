// 7.27 https://www.acmicpc.net/problem/10282
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 10010
#define INF 987654321

using namespace std;

int testNum;
int time[MAX];
vector<pair<int,int>> V[MAX];

void dijkstra(int start){
    priority_queue<pair<int,int>> PQ;
    PQ.push(make_pair(0,start));
    time[start] = 0;

    while(!PQ.empty()){
        int current = PQ.top().second;
        int cost = -PQ.top().first;
        PQ.pop();

        for(int i = 0; i < V[current].size(); i++){
            int next = V[current][i].first;
            int ncost = V[current][i].second;

            if(time[next] > cost + ncost){
                time[next] = cost + ncost;
                PQ.push(make_pair(-time[next], next));
            }
        }
    }
}

int main(){
    cin >> testNum;
    for(int cnt = 0; cnt < testNum; cnt++){
        
        int n, d, c;
        cin >> n >> d >> c;
        
        for(int i = 0; i < d; i++){
            int a, b, c;
            cin >> a >> b >> c;
            V[b].push_back(make_pair(a,c));
        }

        for(int i = 1; i <= n; i++){
            time[i] = INF;
        }

        dijkstra(c);
        
        int hacked, hackTime;
        hacked = hackTime = 0;
        for(int i = 1; i <= n; i++){
            if(time[i] != INF){
                hacked++;
                hackTime = max(hackTime, time[i]);
            }
        }
        cout << hacked << " " << hackTime << endl;

    }
    return 0;
}