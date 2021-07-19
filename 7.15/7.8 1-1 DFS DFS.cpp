/*백준 1260 dfs bfs*/

#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000;

int N, M, V; //정점, 간선, 시작
int map[MAX][MAX]; //행렬 그래프
bool visit[MAX]; //방문 여부
queue<int> q;

//방문 여부 리셋
void reset(){
    for (int i = 1; i <= N; i++){
        visited[i] = 0;
    }
}

//DFS : 재귀적으로 실행
void DFS(int v){
    //queue.push(element) - 큐에 element input
    q.push(v);
    visited[v] = true;
    cout << v <<" ";

//q가 비어있지 않다면 :: queue.empty() - 큐가 비었는지 아닌지 확인시켜주는 함수
    for (int w = 1; w <= N, w++ ){
        if(map[v][w] == 1 && visited[w] == 0){ // 만약 간선이 있고 방문하지 않았으면
                DFS(w); //DFS를 재귀적으로 실행
        }
    }        
}

//BFS
void BFS(int v){
    q.push(v);
    visited[v] = true;
    cout << v <<" ";

    //큐가 비어있지 않다면
    while(!q.empty()){
        //v에 큐 맨 앞 요소 저장 후 pop
        v = q.front();
        q.pop(); //queue.pop() - 큐 맨 앞 요소 out

        for(int w = 1; w <= N; w++){
            if(map[v][w] == 1 && visited[w] == 0){// 만약 간선이 있고 방문하지 않았으면
                q.push(w); //w를 큐 맨 뒤에 넣고
                visitied[w] == true; //방문 처리 하고
                cout << w << " ";
            }
        }
    }
}

int main(){
    cin >> N >> M >> V ;
    for (int i =0; i < M; i ++){
        int x, y;// 너네는 간선 표시, map 그리는 용도
        cin >> x >> y ;
        map[x][y] = 1;
        map[y][x] = 1;
    }
    
    reset(); // 방문 기록 초기화
    DFS(V); //DFS 실행

    cout << '\n';
    reset();
    BFS(V);
    
    return 0;
}