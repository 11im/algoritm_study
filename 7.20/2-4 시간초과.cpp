#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define MAX 501
#define INF 987654321
using namespace std;

int N, M, ANS, count;
bool visited[MAX];
vector<pair<int,int>> Vector[MAX]; //vector[번호1][번호2]는 1이 2보다 작으면 1 1이 2보다 크면 2
queue<int> q;

void Input(){
    cin >> N >> M;
    //전체 0으로 초기화
    for(int i = 0; i < M; i++){
        int a, b; //a가 b보다 작다
        cin >> a >> b;
        Vector[a].push_back(make_pair(b, 1));
        Vector[b].push_back(make_pair(a, 2));
    }
}

int Count(int x){

    q.push(x);
    visited[x] = true;
    while(!q.empty()){

        int current = q.front();
        q.pop();

        for(int i = 1; i <= N; i++){
            if(Vector[current][i].second == 1 && visited[i] == false){
                q.push(i);
                Count(i);
                count++;
            }
            if(Vector[current][i].second ==2 && visited[i] == false){
                q.push(i);
                Count(i);
                count++;
            }
            
        }
    }

    if(count == N) ANS++;
    return 0;
}

int main(){

    ANS = 0;
    Input();
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            visited[j] = false;
        }
        count = 0;
        Count(i);
    }

    cout << ANS;
    return 0;
}