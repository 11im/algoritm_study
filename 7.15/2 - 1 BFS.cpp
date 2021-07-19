//백준 1697 숨박꼭질 : BFS 활용

#include <iostream>
#include <queue>
#include <utility>

#define MAX 100000

using namespace std;

int N,K;
bool visited[MAX];

void reset(){
    for(int i = 0; i <= MAX; i++){
        visited[i] = 0;
    }
}

int hideNseek(int N, int K){
    queue<make_pair<int, int>> q; // make_pair : utility에 있고, make_pair<element,element>, 두 개를 한 쌍으로 묶어줌
    q.push(make_pair<N, 0>); // q에 N의 시작 좌표 push
    visited[N] = true; // N 방문 처리

    while(!que.empty()){
        int position = q.front().first; // position에 위치 저장
        int time = q.front().second; //time 에 시간 저장
        q.pop(); //저장하고 out

        if(position == K){ // K를 찾으면 return하고 끝
            return time;
        }
        if(position + 1 <= MAX && !visited[position + 1 ] ){ //+1 할 떄
            q.psuh(make_pair<position + 1, time + 1>); // position +1 하고, time +1 하고
            visited[position + 1] = true; // 방문 처리
        }
        if(position - 1 >= 0 && !visited[position - 1]){
            q.push(make_pair<position - 1, time + 1>);
            visited[position - 1] = true;
        }
        if(position * 2 <= MAX && !visited[position * 2]){
            q.push(make_pair<position * 2, time + 1>);
            visited[position * 2] = true;
        }
    }
}

int main(){
    cin >> N >> K;
    reset();
    cout << hideNseek(N,K) << endl;
    return 0;
}