//백준 14502 연구소 바이러스

#include <iostream>
#include <queue>
#include <utility>
#define MAX 8
using namespace std;

int N, M;
int map[MAX][MAX];
int copy_map[MAX][MAX];
int ans = 0;
int dx[] = {0, 0, -1, 1}; //상하 좌우
int dy[] = {1, -1, 0, 0}; //상하 좌우

void virus(){
    int afterSpread[MAX][MAX];
    queue<pair<int, int>> virusQ;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            afterSpread[i][j] = copy_map[i][j];//afterSpread에 map 복사
            if(afterSpread[i][j] == 2){//바이러스면
                virusQ.push(make_pair(i, j)); //큐에 넣는다
            }
        }
    }

    while(!virusQ.empty()){
        int x = virusQ.front().first;
        int y = virusQ.front().second;
        virusQ.pop();

        for(int i = 0; i < 2; i++){
            int nextY = y +  dy[i];//상하

            for(int j = 2; j < 4; j++){//좌우
                int nextX = x + dx[j];

                if(nextX >= 0 && nextY >=0 && nextX < N && nextY < M){ //x,y가 0보다 크고 N,M 보다 작을 때
                    if(afterSpread[nextX][nextY] == 0){ // 0이면
                        afterSpread[nextX][nextY] = 2; // 전염
                        virusQ.push(make_pair(nextX,nextY)); // 큐에 입력
                    }
                }
            }
        }
    }

    int empty = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(afterSpread[i][j] == 0){//0 세기
                empty++;
            }
        }
    }
    ans = max(ans, empty); // 기존 답이랑 empty랑 비교해서 더 큰 거
}

void wall(int count){
    if(count == 3){
        virus();//벽이 3개니까 끝
        return;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(copy_map[i][j] == 0){
                copy_map[i][j] =1;
                wall(count + 1);//귀납적으로, 지금 세운 곳 말고 다른 곳에 세움
                copy_map[i][j] = 0; //근데 반복문 돌아야하니까 해보고나서 안되면 원상복구
            }
        }
    }
}

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                //빈 칸 발견시
                for(int a = 0; a < N; a++){
                    for(int b = 0; b < M; b ++){
                        copy_map[a][b] = map[a][b]; //맵 복사
                    }
                }
                copy_map[i][j] = 1;// 벽 세워
                wall(1);
                copy_map[i][j] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}