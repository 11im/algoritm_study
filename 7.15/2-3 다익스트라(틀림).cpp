//백준 1753

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define endl "\n"
#define MAX 20000
#define INF 987654321

using namespace std;

int V, E, K;
int Distance[MAX];
vector<pair<int,int>> Vertex[MAX];

void Input(){
    cin >> V >> E >> K;
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Vertex[a].push_back(make_pair(b,c)); //vertex의 index가 시작점, vertex[][0] 이 도착점, vertex[][1]이 가중치
    }
    for(int i = 1; i <= V; i++){
        Distance[i] = INF; //Distance 전체를 무한대로 초기화
    }
}

void Solution(){
    priority_queue<pair<int,int>> PQ; // 우선순위 큐 생성
    PQ.push(make_pair(0,K)); //거리함 시작점
    Distance[K] = 0;

    while(!PQ.empty()){
        int cost = -PQ.top().first; //-를 사용하면 비용의 부호가 역전됨 : 최소힙을 만들어주기 위해서 이 방법을 사용하는데, -를 붙이면 최대값은 최소값이 됨 : 상대적으로 우선순위가 밀려남 : 최소값이 높은 우선순위를 갖게 됨
        int current = PQ.top().second;//큐.first는 cost, second는 점, vertex[][].first는 다음 점, second는 거리
        PQ.pop();

        for(int i =0; i < Vertex[current].size(); i++){
            int next = Vertex[current][i].first;
            int ncost = Vertex[current][i].second;

            if(Distance[next] > cost + ncost){
                Distance[next] = cost + ncost;
                PQ.push(make_pair(-Distance[next],next));
            }
        }
    }
    for (int i = 1 ; i <= V; i++){
        if(Distance[i] == INF) cout << "INF" << endl;
        else cout << Distance[i]<< endl;
    }
}

void solve(){
    Input();
    Solution();
}
int main(){
    ios::sync_with_stdio(false); //c와 c++의 입출력 싱크를 끊어주는 역할 : 이 구문을 사용하면 cin cout의 속도가 빨라지지만 c의 io 함수는 쓰면 안된다. ex printf scanf getchar 등
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}