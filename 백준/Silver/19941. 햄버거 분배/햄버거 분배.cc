// 19941 실버3 햄버거 분배 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N, K; // N(1~20000), K(1~10)
    int pos = 0; // input string에서 현재 위치
    int posP = -1; // input string에서 H를 부여한 P 위치
    int count = 0; // 답: 햄버거 가진 최대 사람 수 

    string input;

    cin >> N >> K;
    cin >> input; // H(햄버거) / P(사람) 으로 구성

    while(pos < input.size()){
        // 왼쪽부터 P에 H 할당
        if(input[pos] == 'H'){
            // pos-K부터 pos+K까지 제일 작은P 찾아서 아직 H 안받았다면 할당 
            for(int i = max(0, pos-K); i <= min(pos+K, N-1); i++){
                if(input[i] == 'P' && posP < i){
                    posP = i;
                    count++;
                    break;
                }
            }
        }
        pos++;
    }
    cout << count;
	return 0;
}