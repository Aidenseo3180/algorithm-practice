//https://seol-limit.tistory.com/46
#include <iostream>
#include <algorithm> 
 
#define endl "\n"

using namespace std;

int d[100001][2], a[100001];

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
   	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
		
	//dp = max at that index
	int ans = a[0];
	for (int i = 0; i < n; i++){
		d[i][0] = d[i][1] = a[i];
		if (i == 0) continue;
		
		//when you don't delete (j == 0)
		d[i][0] = max(d[i - 1][0] + a[i], a[i]);
		//when you delete (j == 1)
		d[i][1] = max(d[i - 1][0], d[i - 1][1] + a[i]);
		
		//compare
		ans = max(ans, max(d[i][0], d[i][1]));
	}
	
	cout << ans;
   
    return 0;
}










