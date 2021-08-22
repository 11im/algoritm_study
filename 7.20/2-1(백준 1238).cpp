//7.20 2-1 https://www.acmicpc.net/problem/1238
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

#define MAX 1010

using namespace std;

int N, M, X;
int TimeToX[MAX];//시간 기록용
int Time[MAX];
int MaxTime = 0;
vector<pair<int,int>> Vector[MAX];

int Input(){
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Vector[a].push_back(make_pair(b,c)); //a는 시작점, b는 도착점, C는 시간
    }
    return 0;
}

int Solve(int start){
    for(int i = 1; i <= N; i++){
        Time[i] = INF;
    }

    priority_queue<pair<int,int>> PQ;
    PQ.push(make_pair(start,0));
    Time[start] = 0;
    
    while(!PQ.empty()){
        int current = PQ.top().first;
        int cost = -PQ.top().second; // 최소값을 뽑아야하니까 -를 붙여서 PQ에 인풋함
        PQ.pop();

        for(int i = 0; i < Vector[current].size(); i++){
            int next = Vector[current][i].first; //현재 점에서 연결된 다음 점
            int ncost = Vector[current][i].second;//다음 점에 대한 시간
            if(Time[next] > cost + ncost){
                Time[next] = cost + ncost;//시간이 기존보다 작으면 update하고 pq에 push
                PQ.push(make_pair(next, -Time[next]));
            }
        }
    }
    return Time[X];
}

int main(){

    Input();//넣고
    
    for(int i = 1 ; i <= N; i++){
        Solve(i);
        Time[X] = TimeToX[i];
    }
    Solve[X];
    for(int i = 0; i <= N; i++){
        MaxTime = max(TimeToX[i] + Time[i], MaxTime);
    }

    cout << MaxTime;
    return 0;
}
