#include <iostream>


#define MAX 101

using namespace std;

int N;
int map[MAX][MAX];
int visited[MAX];

int Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    return 0;
}

int DFS(int current){
    for(int i = 0; i < MAX; i++){
    visited[i] = false;
    }
    for(int i = 0; i < N; i++){
        if(map[current][i] == 1 && visited[i] == 0){
            visited[i] = true;
            DFS(i);
        }
    }
    return 0;
}

int print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;    
}

int main(){
    Input();
    for(int i = 0; i < N; i++){
        DFS(i);
        for(int j = 0; j < N; j ++){
            if(visited[j]==true){
                map[i][j] = 1;
            }
        }
    }

    print();
}