#include <iostream>

using namespace std;

int solution(int a[], size_t a_len, int b[], size_t b_len) {
    
    int result = 0;
 	for (int i = 0; i < a_len; i++){
 		result += a[i]*b[i];
	}
    return result;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int a[] = {-1,0,1};
	int b[] = {1,0,-1};
	
	cout << solution(a, 3, b, 3);
	
}

