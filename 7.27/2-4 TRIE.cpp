#include <iostream>
#include <string>

#define LEN_MAX 11 //전화번호
#define N_MAX 10010 //N개수
#define NODE_MAX N_MAX * LEN_MAX //전체 노드 개수

using namespace std;

struct TRIE{
    bool finished; //종료 여부
    TRIE *Node[LEN_MAX];//번호

    void Insert(char *Str); //insert operation
    bool Call(char *Str); 
};

int N. N_Index;
char Phone[N_MAX][LEN_MAX];
string Answer;
TRIE ROOT, Nodepool[NODE_MAX];

TIRE *Nodeset(){ //새 노드 생성 시
    TRIE *NewNode = &Nodepool[N_Index++]; //전체 트라이의 인덱스 +1
    NewNode -> finished = false; //종료 마킹 false

    for(int i = 0; i < LEN_MAX; i++){ //해당 노드에 할당된 공간 전부 초기화
        NewNode -> Node[i] = NULL;
    }
    
    return NewNode;
}

void TRIE::Insert(char *Str){
    
    if(*Str == NULL){ //재귀적으로 동작할 때 더 이상 입력할 문구가 없으면 종료 마킹 true
        finished = true;
        return;
    }

    int Cur = *Str - '0'; //아스키 코드로 변환 시 char '1' - '0' = 2 - 1 = 1 : 이 부분은 str의 시작 글자를 아스키 코드로 변환해서 계산 후 int로 형변환해서 root에 해당 문자가 연결이 되어있는지 확인하기 위한 용도
    if(Node[Cur] == NULL ){//노드가 없다면 Nodeset()을 통해 새로운 노드 생성
        Node[Cur] = Nodeset();
    }
    Node[Cur] -> Insert(Str +1); //어쨌든 다음 문자로 이동
}

bool TRIE::Call(char *Str){ //str이 null 이 아닌데 finished 가 true -> 이어진 노드가 끝까지 가기 전에 끝난다 : 일관성이 없다

    if(*Str == NULL){
        return true;
    }

    if(finished == true){
        return false;
    }

    int Cur = *Str - '0';
    return Node[Cur] -> Call(Str + 1);

}

void Initialize(){ //초기화
    N_Index = 0;
    ROOT = Nodeset();
}

void Input(){ //전화번호 넣기
    cin >> N;
    for(int i = 0; i < N; i++){
    cin >> Phone[i];
    }
}

void Solution(){//ROOT에 전화번호 연결

    for(int i = 0; i < N; i++){
         ROOT -> Insert(Phone[i]);
    }

    bool flag = true;

    for(int i = 0; i < N; i++){
        if(flag == true) flag = ROOT -> Call(Phone[i]); //계속 Call 돌리기
        if(flag == false) break; //false면 멈추기
    }
    
    if(flag == true) Answer = "YES";
    else Answer = "NO";

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