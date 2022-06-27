#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
   
	int D, K;
	int A[31];	//number of A at index
	int B[31];	//number of B at index
	
	cin >> D >> K;
	
	//initial
	A[1] = 1; B[1] = 0;
	A[2] = 0; B[2] = 1;
	
	for (int i = 3; i <= D; i++){
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}
	
	int ans_A;
	int ans_B;
	//try all the values 1 ~ K
   	for (int i = 1; i <= K; i++){
   		int value = (K - A[D] * i);
   		if (value % B[D] == 0){		//check if B exists by modulus
   			ans_A = i;
   			ans_B = value / B[D];
   			break;
		}
	}
   	
	cout << ans_A << endl << ans_B;
   
    return 0;
}










