// 3758 실버2 KCPC
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Log{
    int id; // auto increment: 시간순 저장 반영 
    int teamId;
    int questionNum;
    int score;
};

struct TeamResult{
    int teamId;
    int totalScore;
    int lastLogId;
    int submitCount;
};

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    // [Team ID, 문제 번호, 점수]
    int T; // test data
    int n, k, t, m; 
    int i, j, s; // (loop) ID, Qnum, score  
    int rank; // output: 테스트 데이터에 대한 팀의 순위 

    cin >> T;

    for(int data = 0; data < T; data++){
        cin >> n >> k >> t >> m; // total teams num, questions, my teamid, total logs num
        
        vector<Log> logs;
        vector<TeamResult> teamResults(n+1);
        // n+1개 만들어서 0 index 버리고 n개 이용
        for(int a=1; a<=n; a++){ teamResults[a] = {a,0,0,0}; }
        
        vector<vector<int>> bestScore(n+1, vector<int>(k+1,0));
        
        for(int log = 0; log < m; log++){
            cin >> i >> j >> s;  // (loop) ID, Qnum, score 
            logs.push_back({log, i, j, s}); // log에 row 추가 
            
            // teamResult update
            teamResults[i].lastLogId = log; 
            teamResults[i].submitCount++;
            
            if(bestScore[i][j] < s){
                teamResults[i].totalScore -= bestScore[i][j];
                bestScore[i][j] = s;
                teamResults[i].totalScore += s;
            } 
        }

        // lambda: return true(a를 b보다 앞으로), false(상관 X)
        sort(teamResults.begin(), teamResults.end(), [](const TeamResult& a, TeamResult& b){
            // totalScore가 높은 순서대로 
            if(a.totalScore!=b.totalScore) return a.totalScore > b.totalScore;
            // submitCount가 작은 순서대로 
            if(a.submitCount!=b.submitCount) return a.submitCount < b.submitCount;
            // 마지막 제출 시간이 더 빠른 순서대로
            if(a.lastLogId!=b.lastLogId) return a.lastLogId < b.lastLogId;
            return false;
        });

        // sort 후에는 정렬된 벡터 -> index로 접근 불가 
        for(int a=0; a<n; a++){
            if(teamResults[a].teamId==t){
                rank = a + 1;
                break;
            }
        }
        cout << rank << "\n";
    }
	return 0;
}
