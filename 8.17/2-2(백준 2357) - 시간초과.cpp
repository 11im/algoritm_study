//https://www.acmicpc.net/problem/2357
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, M;
vector<int> Array;
vector<int> MinTree_Array;
vector<int> MaxTree_Array;
vector<pair<int,int>> Cmd;

int Min(int a, int b){if(a > b) return b; else return a;}
int Max(int a, int b){if(a > b) return a; else return b;}

void Input(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        Array.push_back(a);
    }
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        Cmd.push_back(make_pair(a,b));
    }
}

int Make_SegmentTree(int Node, int Start, int End, bool T){
    //T가 false면 Min, else Max
    if(Start == End){
        if(T == false){
            return MinTree_Array[Node] = Array[Start];
        }
        else{
            return MaxTree_Array[Node] = Array[Start];
        }
    }
    
    int Mid = (Start + End) / 2;
    int Left_Result = Make_SegmentTree(Node * 2, Start, Mid, T);
    int Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End, T);

    if(T == false){
        MinTree_Array[Node] = Min(Left_Result, Right_Result);
        return MinTree_Array[Node];
    }
    else{
        MaxTree_Array[Node] = Max(Left_Result, Right_Result);
        return MaxTree_Array[Node];
    }
}

int Query(int Node, int Start, int End, int Left, int Right, bool T){
    //범위 밖에 있는 경우
    if(Left > End || Right < Start){
        if(T == false) return 2e9;
        else return -2e9;
    }
    //범위 안에 있는 경우
    if(Left <= Start && Right >= End){
        if(T == false) return MinTree_Array[Node];
        else return MaxTree_Array[Node];
    }

    int Mid = (Start + End) / 2;
    int Left_Result = Query(Node * 2, Start, Mid, Left, Right, T);
    int Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right, T);

    if(T == false) return Min(Left_Result, Right_Result);
    else return Max(Left_Result, Right_Result);
}

void Solve(){
    int Tree_Height = ceil(log2(N));
    int Tree_Size = (1 << (Tree_Height + 1));
    MinTree_Array.resize(Tree_Size);
    MaxTree_Array.resize(Tree_Size);

    Make_SegmentTree(1, 0, N - 1, false);
    Make_SegmentTree(1, 0, N - 1, true);

    for(int i = 0; i < Cmd.size(); i++){
        int Left = Cmd[i].first - 1;
        int Right = Cmd[i].second - 1;

        int Min_Result = Query(1, 0, N - 1, Left, Right, false);
        int Max_Result = Query(1, 0, N - 1, Left, Right, true);

        cout << Min_Result << " " << Max_Result << endl;
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