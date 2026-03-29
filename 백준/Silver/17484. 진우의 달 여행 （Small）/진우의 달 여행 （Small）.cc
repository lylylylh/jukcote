// 17484 실버3 진우의 달 여행(small)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// 내 현재 위치, 직전 방향 Left/Straight/Right 
// 깊이 찍고 오면서 가장 작은 값 메모 / 가지치기
int N, M;
vector<vector<int>> spaces;

int DFS(int n, int m, int direct){
    // direct: 0 1 2 == L S R

    if(n == N-1){
        return spaces[n][m];
    }
    int left = 1000, right = 1000, straight = 1000;
    switch (direct)
    {
    case 0:  // S R 만 가능
        if(m >= 0 && m < M){
            straight = DFS(n+1, m, 1);
        }
        if(m < M-1){
            right = DFS(n+1, m+1, 2);
        }
        return spaces[n][m]+min(straight, right);
    
    case 1:  // L R 만 가능
        if(m > 0){
            left = DFS(n+1, m-1, 0);
        }
        if(m < M-1){
            right = DFS(n+1, m+1, 2);
        }
        return spaces[n][m]+min(left, right);

    case 2:  // L S 만 가능
        if(m > 0){
            left = DFS(n+1, m-1, 0);
        }
        if(m >= 0 && m < M){
            straight = DFS(n+1, m, 1);
        }
        return spaces[n][m]+min(straight, left);
    }
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> N >> M;
    spaces.assign(N, vector<int>(M,0));
    vector<int> values(M);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> spaces[i][j];
        }
    }

    for(int i=0; i<M; i++){
        int left = 1000, right = 1000, straight = 1000;

        if(i > 0){
            left = DFS(1, i-1, 0);
        }
        if(i >= 0 && i < M){
            straight = DFS(1, i, 1);
        }
        if(i < M-1){
            right = DFS(1, i+1, 2);
        }
        values[i] = spaces[0][i] + min({left, right,straight});
    }
    sort(values.begin(), values.end());

    cout<< values[0];
	return 0;
}
