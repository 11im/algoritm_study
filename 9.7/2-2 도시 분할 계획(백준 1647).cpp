//https://www.acmicpc.net/problem/1647
//마을을 분리시켜야 하므로 크러스컬 알고리즘을 통해 MST를 구한 후 그 중에서 최대값 뺴기
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, Answer;
int Parent[100001];
vector<pair<int,pair<int,int>>> V;
vector<int> V2;

void Input(){
    cin >> N >> M;
    int Cost, From, To;
    for(int i = 0; i < M; i++){
        cin >> From >> To >> Cost;
        V.push_back(make_pair(Cost, make_pair(From, To)));
    }
    sort(V.begin(), V.end());
}

int Find_Parent(int x){
    if(x == Parent[x]) return x;
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
    for(int i = 1; i <= N; i++){
        Parent[i] = i;
    }

    for(int i = 0; i < M; i++){
        if(Same_Parent(V[i].second.first, V[i].second.second) == false){
            Union(V[i].second.first, V[i].second.second);
            V2.push_back(V[i].first);
        }
    }

    for(int i = 0; i < V2.size() - 1; i++){
        Answer = Answer + V2[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    cout << Answer <<"\n";

    return 0;
}