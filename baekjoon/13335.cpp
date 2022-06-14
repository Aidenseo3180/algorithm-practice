#include <iostream>
#include <algorithm> 
#include <queue>

#define endl "\n"

using namespace std;

int arr[1001];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	//n : number of trucks
	//w : length of bridge (numbers of cars that can pass bridge at the same time)
	//L : max weight bridge can take
	int n, w, L;
	cin >> n >> w >> L;

	queue<int> q;

	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++){
		
		while(1){
			//if size = length of bridge (number of cars that can be on the bridge at a time)
	        if(q.size() == w){
	            sum -= q.front();
	            q.pop();
	        }
	        //if not meeting the weight yet,
	        if(sum + arr[i] <= L) break;
	        
	        q.push(0);
	        ans ++;
        }
        
        //add to queue
        q.push(arr[i]);
        sum+= arr[i];
        ans++;
		
	}
	ans += w;

	cout << ans;
	
	return 0;
}








