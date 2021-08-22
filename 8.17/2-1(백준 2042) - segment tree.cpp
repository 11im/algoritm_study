//구간 합 구하기 https://www.acmicpc.net/problem/2042

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, K;
vector<long long> Arr; //최초 입력 배열
vector<long long> Tree_Array; //Tree Node 배열
vector<pair<int,pair<int, long long>>> Cmd; //명령

void Input(){
    cin >> N >> M >> K;
    
    //최초 입력 배열
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        Arr.push_back(a);
    }
    //명령 입력
    for(int i = 0; i < M + K; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Cmd.push_back(make_pair(a,make_pair(b,c)));
    }
}

long long Sum(int Node, int Start, int End, int Left, int Right){
    //범위 밖에 있는 경우
    if(Left > End || Right < Start) return 0;
    //목표 범위 안에 완전히 속해있는 경우
    if(Left <= Start && Right >= End) return Tree_Array[Node];
    
    //애매하게 걸쳐 있는 경우
    int Mid = (Start + End) / 2; //중간점 찾아서
    long long Left_Result = Sum(Node * 2, Start, Mid, Left, Right); //왼쪽 따로
    long long Right_Result = Sum(Node * 2 + 1, Mid + 1, End, Left, Right);//오른쪽 따로
    return Left_Result + Right_Result;
}

//Segment Tree 만들기
long long Make_STree(int Node, int Start, int End){
    //시작 == 끝 : leaf node인 경우, 해당 노드에 Array 값 assign
    if(Start == End){
        return Tree_Array[Node] = Arr[Start];
    }

    //기준
    int Mid = (Start + End) / 2;
    //왼쪽 합(재귀)
    long long Left_Result = Make_STree(Node * 2, Start, Mid);
    //오른쪽 합(재귀)
    long long Right_Result = Make_STree(Node * 2 + 1, Mid, End);
    //트리에 값 넣기
    Tree_Array[Node] = Left_Result + Right_Result;

    return Tree_Array[Node];
    //return 값을 설정해서 재귀적으로 돌 수 있도록
}

void Update_STree(int Node, int Start, int End, int Index, long long Difference){
    //case 1 : 변경 노드가 현재 범위 밖인 경우 break
    if(Index < Start || Index > End) return; 
    //case 2 : 변경 노드가 현재 범위 안에 속할 경우
    Tree_Array[Node] = Tree_Array[Node] + Difference;

    //leaf node가 아닌 경우에는 계속 탐색
    if(Start != End){
        int Mid = (Start + End) / 2;
        Update_STree(Node * 2, Start, Mid, Index, Difference);
        Update_STree(Node * 2 + 1, Mid + 1, End, Index, Difference);
    }
}

void Solve(){
    //Tree 높이 : log2(N)을 올림한 값
    int Tree_Height = (int)ceil(log2(N));
    //Tree 크기 : 2 ^ (높이+1) :: 0번 노드는 제외되기 때문에 실제 사용 노드는 Size - 1
    int Tree_size = (1 << (Tree_Height + 1));
    //크기 조정
    Tree_Array.resize(Tree_size);
    //시작 노드 번호 1 :: root node : 전체 합을 가지고 있음
    //총 0~N-1까지 총 N개의 leaf node를 가지고 있음
    Make_STree(1, 0, N - 1);

    for(int i = 0; i < Cmd.size(); i++){
        int Command = Cmd[i].first;
        //1이면 업데이트
        if(Command == 1){
            int Index = Cmd[i].second.first - 1;
            long long value = Cmd[i].second.second;
            long long Difference = value - Arr[Index];
            Arr[Index] = value;
            Update_STree(1, 0, N - 1, Index, Difference);
        }
        //2이면 합
        else{
            int Left = Cmd[i].second.first - 1;
            int Right = Cmd[i].second.second - 1;
            long long Result = Sum(1, 0, N - 1, Left, Right);
            cout << Result << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    return 0;
}