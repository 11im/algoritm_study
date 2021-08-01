//https://programmers.co.kr/learn/courses/30/lessons/60060
//참고 https://yabmoons.tistory.com/474

#include <string>
#include <vector>
#include <map>

#define W_MAX 1000001
#define L_MAX 10001

using namespace std;

struct TRIE{
    int ChildCount;
    bool finished;
    TRIE *Node[L_MAX];

    void Insert(char *Str);
    int Search(char * Str);
}

int N_Index;
vector<int> Answer;
TRIE  NodePool[W_MAX * 2];
TRIE Word[L_MAX], RWord[L_MAX];

TRIE *NodeSet(){
    TRIE *NewNode = &NodePool[N_Index++];
    NewNode -> finished = false;
    NewNode -> ChildCount = 0;
    for(int i = 0; i < L_MAX; i++){
        NewNode -> Node[i] = NULL;
    }

    return NewNode;
}

void TRIE::Insert(const char *Str){
    ChildCount++;
    if(Str == NULL){
        finished = true;
        return;
    }
    int Curr = *Str - 'a';
    if(Node[Curr] == NULL){
        Node[Curr] = NodeSet();
    }
    Node[Curr] -> Insert(Str + 1);
}

int TRIE::Search(const char *Str){
    if(*Str == '?') return ChildCount;

    int Curr = *Str - 'a';
    if(Node[Curr] == NULL) return 0;
    return Node[Curr] -> Search(Str + 1);
}

void Initialize(){
    N_Index = 0;
    ROOT = NodeSet();
}

int Check_Revers(string S){ //?가 앞에 있는지 뒤에 있는지
    if(S[0] == '?') return 0;
    if(S[S.length() -1] == '?') return 1;
}

string Reverse(string S){
    string Temp = "";
    for(int i = S.length() - 1; i >=0;  i--){ //뒤에서부터
        Temp = Temp + S[i]
    }
    return Temp;
}


vector<int> solution(vector<string> words, vector<string> queries) {

    Initialize();
    for(int i = 0; i < words.size(); i++){ //일단 words 때려넣고
        string S = words[i];
        int Len = S.length();
        
        if(Word[Len] == NULL){
            Word[Len] = NodeSet();
            Word[Len] -> Insert(S.c_str());
        }

        string ReverseS = Reverse(S);
        if(RWord[Len] == NULL){
            RWord[Len] = NodeSet();
            RWord[Len] -> Insert(ReverseS.c_str());
        }
    }

    map<string, int> MAP;//MAP은 key - value로 구성된 컨테이너
    for(int i = 0; i < queries.size(); i++){
        string S = queries[i];
        if(MAP.count(S) == 0){ //만약 S가 처음으로 검색되는 거면 S의 count가 0, 만약 중복이면 1+
            MAP(S) = i;

            int Len = S.length();
            int State = Check_Reverse(S);

            if(State == 1){//?가 뒤에 있으면 정방향
                if(Word[Len] == NULL){ //해당 길이의 trie가 없으면
                    answer.push_back(0);
                }
                else answer.push_back(Word[Len] -> Search(S.c_str()));
            }
            else{
                if(RWord[Len] == NULL){
                    answer.push_back(0);
                }
                else answer.push_back(RWord[Len] -> Search(S.c_str()));
            }
        }
        else answer.push_back(answer[MAP[S]]);//이전에 검색된 적이 있으므로 해당 index를 반환
    }

    return answer;

}