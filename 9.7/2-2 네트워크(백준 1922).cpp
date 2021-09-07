//https://www.acmicpc.net/problem/1922

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Answer;
int Parent[1001];
vector<pair<int,pair<int,int>>> V;

void Input(){
    cin >> N;
    cin >> M;

    for(int i = 0; i < M; i++){
        int From, To, Cost;
        cin >> From >> To >> Cost;
        V.push_back(make_pair(Cost, make_pair(From, To)));
    }
    sort(V.begin(), V.end());
}

int Find_Parent(int x){
    if(Parent[x] == x) return x;
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
            Answer = Answer + V[i].first;
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