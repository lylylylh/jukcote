#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N, count = 0;
    string str, input;

    cin >> N;
    cin >> str;
    std::sort(str.begin(), str.end());

    int j, k, diff, common;
    for(int i = 1; i < N; i++){
        cin >> input; 
        std::sort(input.begin(), input.end());

        common = 0; j = 0; k = 0;

        while(j < str.size() && k < input.size()){
            if(str[j] == input[k]){ common++; j++; k++; }
            else if(str[j] < input[k]) j++;
            else k++;
        }

        int diff = (str.size() - common) + (input.size() - common);
        
        if(diff <= 2 && abs((int)str.size() - (int)input.size()) <= 1){
            count++;
        }
    }

    cout << count;

	return 0;
}
