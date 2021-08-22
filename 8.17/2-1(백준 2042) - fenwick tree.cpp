//구간 합 구하기 https://www.acmicpc.net/problem/2042 
//펜윅트리는 비트연산을 사용함, 간단한 코드, 연산
//모든 펜윅트리는 세그먼트 트리로 구현 가능하지만 일부 세그먼트 트리는 펜윅트리로 구현이 안되는 경우가 있다 ex) 특정 값 찾기
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, K;
vector<long long> Arr;
vector<long long> Fenwick_Tree;
vector<pair<int, pair<int, long long>>> Cmd;

void Input(){
    cin >> N >> M >> K;
    Arr.resize(N + 1);
    Fenwick_Tree.resize(N + 1);
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        Arr[i] = a;
    }
    for(int i = 0; i < M + K; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Cmd.push_back(make_pair(a, make_pair(b,c)));
    }
}

void Update(int Index, long long Value){
    while(Index < Fenwick_Tree.size()){
        Fenwick_Tree[Index] = Fenwick_Tree[Index] + value;
        Index = Index + (Index & -Index);
    }
}

void Make_FTree(){
    for(int i = 1; i <= N; i++){
        Update(i,Arr[i]);
    }
}

long long Sum(int Index){
    long long sum = 0;
    
    while(Index > 0){
        sum += Fenwick_Tree[Index];
        Index = Index - (Index & -Index);
    }
    return sum;
}

void Solve(){
    Make_FTree();

    for(int i = 0; i < Cmd.size(); i++){
        int Command = Cmd[i].first;
        //업데이트
        if(Command == 1){
            int Index = Cmd[i].second.first;
            long long value = Cmd[i].second.second;
            long long Difference = value - Arr[Index];
            Arr[Index] = value;
            Update(Index, Difference);
        }
        else{
            int Left = Cmd[i].second.first;
            int Right = Cmd[i].second.second;
            cout << Sum(Right) - Sum(Left) << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    return 0;
}