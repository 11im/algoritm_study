#include <string>
#include <vector>
#include <queue>

#define MAX 210

using namespace std;

bool visited[MAX]
vector<int> V[MAX];

void BFS(int start){
    
    queue<int> Q;
    Q.push(start);
    visited[start] = true;

    while(!Q.empty()){
        int current = Q.front();
        Q.pop();
        for(int i = 0; i < V[current].size(); i++){
            int next = V[current][i];
            if(visited[next] == false){
                visited[next] = true;
                Q.push(next);
            }
        }
    }
}



int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int from = i;
            int to = j;
            if(computers[i][j] == 1){
                V[i].push_back(j);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(visited[i] != true){ //해당 점이 방문되지 않은 경우에만 BFS 실행하도록
            BFS(i);
            answer++;
        }
    }
   
    return answer;
}