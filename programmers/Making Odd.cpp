#include <iostream>

using namespace std;

bool isPrime(int n){
	
	if (n == 0 || n == 1) return false;	
	
	for (int i = 2; i < n / 2; i++){
		if (n % i == 0) return false;
	}
	return true;
	
}

int solution(int nums[], size_t nums_len) {
        
	int answer = 0;
    
	for (int i = 0; i < nums_len; i++){
		for (int j = i + 1; j < nums_len; j++){
			for (int k = j + 1; k < nums_len; k++){
				
				int n = nums[i] + nums[j] + nums[k];			
				if (isPrime(n) == 1){
					answer++;	
				}
			}	
		}
	}

	return answer;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int a[] = {1,2,7,6,4};
	
	cout << solution(a, 5);
	
}

