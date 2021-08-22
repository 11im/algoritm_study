//7.20 2-3 https://www.acmicpc.net/problem/11404

#include <iostream>
#include <algorithm>

#define INF 987654321
#define MAX 101

using namespace std;

int N, M, a, b, c;
int map[MAX][MAX];

void Input(){
    cin >> N >> M; //N은 점 개수 M은 버스 수

    //전체 INF로 초기화
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
          map[i][j] = INF;
        }
    }

    
    //입력 받기 : a는 시작 도시 b는 도착 도시 c는 거리
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        if(map[a][b] > c){
            map[a][b] = c;
        }
    }
}

void FW(){
    for(int i = 1; i <= N; i++){ //i점을 거치는 경우
        for(int j = 1; j <= N; j++){ //시작점
            for(int k = 1; k <= N; k++){//도착점
                if(map[j][i] != INF && map[i][k] != INF){
                    map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
                }
            }
        }
    }
}

int main(){
    Input();
    FW();

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j || map[i][j] == INF){ // 시작점 = 도착점일 때 혹은 INF일 때 0 프린트
                cout << 0 << " ";
            }
            else cout << map[i][j] << " "; // 아니면 map[i][j] 출력
        }
        cout << endl;
    }
    return 0;
}
