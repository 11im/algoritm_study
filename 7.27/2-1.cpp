// 7.27 BFS https://programmers.co.kr/learn/courses/30/lessons/49189#
//다익스트라로도 풀 수 있음

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 20010

using namespace std;

int distance[MAX];
bool visited[MAX];
int maxNum;
vector<int> V[MAX];

void BFS(int start){
   
    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while(Q.empty() != true){
    
        int current = Q.front();
        Q.pop();
    
        for(int i = 0; i < V[current].size(); i++){

            int next = V[current][i];

            if(visited[next] == false){
                visited[next] = true;
                distance[true] = distance[current] + 1;
                Q.push(next);
                maxNum = max(maxNum, distance[next]);
            }
        }
    }
}


int solution(int n, vector<vector<int>> edge) {

    int answer = 0;
    int maxNum = 0;

    for(int i = 0; i < edge.size(); i++){
        int from = edge[i][0];
        int to = edge[i][1];
        V[from].push_back(to);
        V[to].push_back(from);
    }

    BFS(1);
    
    for(int i = 1; i <= n; i++){
        if(distance[i] == maxNum){
            answer++;
        }
    }

    return answer;
}
