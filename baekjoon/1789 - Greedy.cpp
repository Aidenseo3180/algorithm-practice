//https://chanhuiseok.github.io/posts/baek-31/
#include <iostream>

#define endl "\n"

using namespace std;

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	long long S;
	cin >> S;
	
	long long sum = 0, num = 1;
	int cnt = 0;
	
	while(1){
		sum = sum + num;
		cnt++;
				
		if (sum > S){
			cnt--;
			break;
		}
		num++;
	}
	
	cout << cnt;
}
















