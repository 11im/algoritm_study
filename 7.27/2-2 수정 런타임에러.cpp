#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 50

using namespace std;

bool visited[MAX];
int DIST = MAX;

bool Possible(string a, string b){
    int count = 0;
    for(int i = 0, i < a.size(), i++){
        if(a[i] != b[i]){
            count++;
        }
        if(count > 1){
            break;
        }
    }
    if(flag == 1) return true;
    else return false;
}

void dfs(string begin, string target, vector<string> words, int dist){
    if(begin == target){
        answer = min(DIST, dist);
        return;
    }
    for(int i = 0; i < words.size(); i++){
        if(diff[begin, words[i]] == true && visited[i] == false){
            check[i] = true;
            dfs(words[i], target, words, dist + 1);
            check[i] = false;
        }
    }
    return;
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    dfs(begin, target, words, 0);
    if(DIST == MAX){
        return 0;
    }
    else answer = DIST;
    return answer;
}