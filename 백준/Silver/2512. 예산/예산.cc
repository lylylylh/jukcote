// 2512 실버2 예산
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, r, sum = 0, max = 0;
    vector<int> regions;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> r;
        sum += r;
        if(r > max) max = r;
        regions.push_back(r);
    }
    cin >> M;
    if(sum <= M) { cout << max; }
    else{
        sort(regions.begin(), regions.end());
        // 모든 지방에 요청 금액 불가
        if(M < regions[0]*N){
            cout << int(M / N);
            return 0;
        }
        int line = N; // [N-line]부터 상한액 
        int safe = 0; // 상한액에 반영 받지 않을 금액
       
        while(line > 1){ 
            safe += regions[N-line]; // 최솟값부터 더해줌 
            if((M - safe) < regions[N-line+1]*(line-1)){
                // 해당 루프도 상한액보다 큼
                cout << int((M-safe)/(line-1));
                return 0;
            }
            line--;
        }
    }
	return 0;
}
