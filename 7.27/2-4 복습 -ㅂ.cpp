#include <iostream>
#include <string>

//필요한 기능 2개 : insert, check
//구조체에 필요한 구성 : 전번을 저장하는 node(max 11), finished flag

#define L_MAX 11
#define N_MAX 10010
#define T_MAX L_MAX * N_MAX

using namespace std;

struct TRIE{
    bool finished;
    TRIE *Node[L_MAX];

    void Insert(char *Str);
    void Check(char *Str);
}

int N, N_Index;
string Answer;
char Phone[N_MAX][L_MAX];
TRIE ROOT, Nodepool[T_MAX];

TRIE *NodeSet(){//전번 저장 공간 초기화, index + 1, finished = false
    TRIE *NewNode = &Nodepool[N_Index + 1];
    NewNode -> finished = false;
    for(int i = 0; i < L_MAX; i++){
        NewNode -> Node[i] = NULL;
    }
    return NewNode;
}

void TRIE::Insert(char *Str){ //재귀 동작, 다음 글자로 계속 이동, 끝나면 finished true, 노드가 없으면 새 노드 생성
    if(*Str == NULL){
        finished = true;
        return;
    }

    int Cur = *Str - '0';

    if(Node[Cur]==NULL){
        Node[Cur] = NodeSet();
    }
    
    return Node[Cur] -> Insert(Str + 1);
}

bool TIRE::Check(char *Str){ //재귀 동작, 입력된 문자가 끝나기 전에 finished true면 false 아니면 true로 계속 진행하도록
    if(*Str == NULL) return true;
    if(finished == true) return false;

    int Cur = *Str - '0';
    return Node[Cur] -> Check(Str + 1);
}

void Initialize(){
    N_Index = 0;
    ROOT = NodeSet();
}
void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Phone[i];
    }
}
void Solution(){//root에 전화번호들 연결 후 CHECK하기
    bool flag;
    flag = true;

    for(int i = 0; i < N; i++){
        ROOT -> Insert(Phone[i]);
    }

    for(int i = 0; i < N; i++){
        if(flag == true) flag = ROOT -> Call(Phone[i]);
        if(flag == false) break;
    }

    if(flag == true) Answer = "YES";
    else Answer = "NO"

    cout << Answer << endl;
}

void Solve(){
    int testcount;
    cin >> testcount;
    for(int i = 1; i <= testcount; i++){
        Initialize();
        Input();
        Solution();
    }
}

int main(){

    ios::sync_with_stdio(false); //요거는 cout, cin 속도 높여주는 설정(대신 cstring 을 사용할 수 없음)
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}
