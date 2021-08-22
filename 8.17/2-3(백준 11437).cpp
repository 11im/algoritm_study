//https://www.acmicpc.net/problem/11437

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50001

int N, M;
vector<int> Node[50001];
queue<int> Q;
bool Visited[50001];
int Parent[50001];
int Depth[50001];

void Input(){
    cin >> N;
    for (int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        Node[a].push_back(b);
        Node[b].push_back(a);
    }
}

int LCA(int a, int b){
    //편의를 위해 b가 더 깊이 있도록 설정
    if(Depth[a] > Depth[b]) swap(a,b);
    //깊이가 같아질 때까지 b 부모 찾기
    while(Depth[a] != Depth[b]) b = Parent[b];

    while(a != b){
        a = Parent[a];
        b = Parent[b];
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Input();
    
    Visited[1] = true;
    Q.push(1);

    while(!Q.empty()){
        int a = Q.front();
        Q.pop();

        for(int i = 0; i < Node[a].size(); i++){
            if(Visited[Node[a][i]] != true){
                Depth[Node[a][i]] = Depth[a] + 1;
                Parent[Node[a][i]] = a;
                Visited[Node[a][i]] = true;
                Q.push(Node[a][i]);
            }
        }
    }

    cin >> M;
    
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }

}