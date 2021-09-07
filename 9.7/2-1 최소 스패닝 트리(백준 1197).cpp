//https://www.acmicpc.net/problem/1197
//크러스컬 알고리즘 : 간선의 Cost를 오름 차순으로 정렬하고 낮은 Cost부터 Union-Find 진행하면서 모든 노드가 연결될 때까지 반복

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int V, E, Answer;
int Parent[100001];
vector<pair<int,pair<int,int>>> Vector;

void Input(){
    cin >> V >> E;

    int From, To, Cost;
    
    for(int i = 0; i < E; i++){
        cin >> From >> To >> Cost;
        Vector.push_back(make_pair(Cost, make_pair(From, To)));
    }
    //cost를 기준으로 오름차순으로 정렬
    sort(Vector.begin(), Vector.end());
}   

//union-find 하기 위해 부모 찾기
int Find_Parent(int x){
    if (Parent[x] == x) return x;
    else return Parent[x] = Find_Parent(Parent[x]);
}

void Union(int x, int y){
    x = Find_Parent(x);
    y = Find_Parent(y);

    if(x != y) Parent[y] = x;
}

bool Same_Parent(int x, int y){
    x = Find_Parent(x);
    y = Find_Parent(y);

    if(x == y) return true;
    else return false;
}

void Solve(){
    //Union-Find 하기 전에 초기화
    for(int i = 1; i <= V; i++){
        Parent[i] = i;
    }

    for(int i = 0; i < E; i++){
        if(Same_Parent(Vector[i].second.first, Vector[i].second.second) == false){
            Union(Vector[i].second.first, Vector[i].second.second);
            Answer = Answer + Vector[i].first;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    cout << Answer << "\n";
    return 0;
}