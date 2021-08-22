class Solution {
public:
    int m, n;
    int answer;
    
    
    int compare(vector<int>& stuednt, vector<int>& mentor){
        int score = 0;
        for(int i = 0; i < student.size(); i++){
            score += (student[i] == mentor[i]);
        }
        return score;
    }

    void Permutation(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, int sum, int assign[]){
        if(i == m){
            answer = max(answer, sum);
        }
        for(int j = 0; j < m; j++){
            if(assign[j] == 0){
                assign[j] = 1;
                int score = compare(students[i], mentors[j]);
                sum += score;
                i++;
                Permutation(students, mentors, i, sum, assign);
                assign[j] = 0;
            }
        }
    }


    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        m = students.size() - 1;
        n = students[0].size();
        assign[8] = {0};
        answer = 0;
        int sum = 0;

        Permutation(students, mentors, 0, sum, assign);
        return answer;
    }