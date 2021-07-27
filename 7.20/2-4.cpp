#include <iostream>
#include <algorithm>

#define MAX 501
#define INF 987654321 //대소관계만 파악하면 되기 때문에 이 문제에서는 무한대로 초기화할 필요 없음

using namespace std;

int N, M, ANS;

int height[MAX][MAX];

void Input(){
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            height[i][j] = INF;
        }
    }
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        height[a][b] = 1;
    }
}

void FW(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(height[j][i] != INF && height[i][k] != INF){
                    height[j][k] = min(height[j][k], height[j][i]+height[i][k]);
                }
            }
        }
    }
}

int main(){

    ANS = 0;
    
    Input();
    FW();

    for(int i = 1; i <= N; i++){ //FW 진행해서 연결되어 있으면 count++, 아니면 안셈
        int count = 0;
        for(int j = 1; j <= N; j++){
            if(height[i][j] != INF || height[j][i] != INF){
                count++;
            }
        }
        if(count == N-1){ //근데 나 빼고 다른 모든 점이랑 연결돼있으면 ANS++
            ANS++;
        }
    }

    cout << ANS;
    return 0;

}