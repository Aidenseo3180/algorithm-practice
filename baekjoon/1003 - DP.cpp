#include <iostream>

#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	
	long long zero[41], one[41];
	
	zero[0] = 1;	//number of 0
	zero[1] = 0;
	
	one[0] = 0;		//number of 1
	one[1] = 1;
	
	//bottom up. From pieces, add up all the way to top
	for (int i = 2; i <= 40; i++){
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}
	
	//output
	while(T--){
		int input;
		cin >> input;
		
		cout << zero[input] << " " << one[input] << endl;
	}
		
}	

/*	explanaion : 

Say 0 : zero[0] = 1, one[0] = 0 & 1 : zero[1] = 0, one[1] = 1
2 is 0 + 1 -> so add zero and one of 0 & 1
3 is 2 + 1 -> so add zero and one of 2 & 1
so on.....

And we can easily find them by adding from bottom all the way to top
*/



