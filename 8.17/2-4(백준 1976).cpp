//https://www.acmicpc.net/problem/1976

#include <iostream>
#include <vector>

#define MAX 987654321

using namespace std;

int N, M;
int Parent[201];

int Find(int x){
    if(Parent[x] == x) return x;
    return Parent[x] = Find(Parent[x]);
}

void Union(int a, int b){
    a = Find(a); b = Find(b);
    if(a == b) return;
    Parent[a] = b;
    Find(a);
}

void Input(){
    cin >> N >> M;
    
    //모든 노드의 부모 노드 초기화
    for(int i = 0; i < 201; i++){
        Parent[i] = i;
    }

    //연결되어 있으면 Union
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <=N; j++){
            int a; cin >> a;
            if(a == 1) Union(i,j);
        }
    }
}

int main(){
    int Start, End;
    bool Flag;

    cin >> start;
    fo(int i= 1; i < M; i++){
        cin >> end;
        if(flag != true) continue;
        if(Find(Start) != Find(End)) flag = false;
        start = end;
    }

    if(flag == true) cout << "YES";
    else cout << "NO";
}