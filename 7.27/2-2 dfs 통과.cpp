// 7.27 https://programmers.co.kr/learn/courses/30/lessons/43162
#include <string>
#include <vector>

using namespace std;

bool visited[201];

void DFS(int start, vector<vector<int>> &computers, int n){
    visited[start] = true;
    for(int i = 0; i < n; i++){
        if(visited[i] != true && computers[start][i] != 0){
            DFS(i, computers, n);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] != true){
            DFS(i, computers, n);
            answer++;
        }
    }

    return answer;
}