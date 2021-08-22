//1947. Maximum Compatibility Score Sum https://leetcode.com/contest/weekly-contest-251/problems/maximum-compatibility-score-sum/

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int answer, sum;
        int m = students.size();
        int n = students[0].size();

        //compare func
        int compare(vector<int> &student, vector<int> &mentor){
            int score = 0;
            for(i = 0 ; i < student.size(); i++){
                if(student[i] == mentor[i]){
                    score++;
                }
            }
            return score;
        }

        //search max
        void Permutation(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, int sum, int assign[]){
            if(i == m){ //compare
                answer = max(sum, answer);
                return;
            }

            for(int j = 0; j < m; j++){
                
                if(assign[j] == 0){ //whether j is assigned or not
                    int score = compare(students[i], mentors[j]);
                    assign[j] = 1;
                    sum += score;
                    i++;
                    Permutation(students, mentors, i, sum, assign);//recursion
                    assign[j] = 0;//reset for recursion
                }
            }
        }

        int assign[8] = {0};
        sum = answer = 0;
        Permutation(students, mentors, 0, sum, assign);
        return answer;     
    }
};