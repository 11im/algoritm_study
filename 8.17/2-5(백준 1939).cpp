//https://www.acmicpc.net/problem/1939

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int N, M, MAX_WEIGHT, Start, End;
bool Visited[MAX];
vector<pair<int, int>> V[MAX];

int Max(int a, int b){
    if(a > b) return a;
    else return b;
}

void Input(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        V[start].push_back(make_pair(end, weight));
        V[end].push_back(make_pair(start, weight));
        
        MAX_WEIGHT = Max(weight, MAX_WEIGHT);
    }

    cin >> Start >> End;
}

bool BFS(int Cur_Cost){
    queue<int> Q;
    Q.push(Start);
    Visited[Start] = true;

    while(!Q.empty()){
        int Current = Q.front();
        Q.pop();

        if(Current == End) return true;
        
        for(int i = 0; i< V[Current].size(); i++){
            int Next = V[Current][i].first;
            int Next_Cost = V[Current][i].second;

            if(!Visited[Next] && Next_Cost >= Cur_Cost){
                Visited[Next] = true;
                Q.push(Next);
            }
        }
    }
    return false;
}

void Solve(){
    int Down = 0;
    int Top = MAX_WEIGHT;
    while(Down <= Top){
        memset(Visited, 0, sizeof(visited));
        int Mid = (Down + Top) / 2;
        if(BFS(Mid)) Down = Mid + 1;
        else Top = Mid - 1;
    }
    cout << Top << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    return 0;
}