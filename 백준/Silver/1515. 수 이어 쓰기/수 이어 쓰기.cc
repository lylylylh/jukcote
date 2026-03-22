// 1515 실버2 수 이어 쓰기 
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N = 1;
    int pos = 0; // input에서 현재 매칭 위치 
    string input, Nstr;

    cin >> input;    
     
    while(pos < (int)input.size()){
        Nstr = to_string(N);

        for(char c: Nstr){
            if(pos < (int)input.size() && c == input[pos]) {
                pos++;   // input의 현재 위치와 Nstr의 c가 같다면 pos 앞으로 전진
            }
        }
        N++;
    }
    cout << N-1;
	return 0;
}