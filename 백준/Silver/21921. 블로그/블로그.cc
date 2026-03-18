// 21921 실버3 블로그
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N, X, today, sum = 0, max = 0, period = 1;
    vector<int> visitors;

    cin >> N >> X;
    // 0 ~ X-1 => N-X ~ N-1
    for(int i = 0; i < N; i++){
        cin >> today;
        visitors.push_back(today);
        sum += today; 
        if(i == X-1) { max = sum; } // max 초기화: 첫 X개 sum 
        if(i >= X){
            sum -= visitors[i-X]; // 범위에서 벗어나는 제일 앞의 값 빼주기
            // if(max <= sum){
            //     if(max == sum) { period++; }// 기간 개수 증가
            //     max = sum;  // 새로운 max값 
            // } => period 초기화 안됨 멍청이
            if(sum > max){
                max = sum;
                period = 1; // 새로운 최댓값 -> 기간 리셋 
            } else if(sum == max){
                period++;
            }
        }
    }

    if(max ==0){
        cout << "SAD";
        return 0;
    }
    cout << max << "\n" << period;
	return 0;
}
