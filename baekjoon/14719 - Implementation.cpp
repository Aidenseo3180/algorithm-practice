//https://hwan-shell.tistory.com/276
#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int N, M;
int ans = 0;

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	vector<int> v(M);
	
	for (int i = 0; i < M; i++){
		cin >> v[i];
	}

	//ignore first / end of blocks b/c it's gonna be either wall or no water can be stored there (so no point of searching)
	for (int i = 1; i < M - 1; i++){
		int left = 0, right = 0;
		
		//search largest left
		for (int j = 0; j < i; j++){
			left = max(left, v[j]);
		}
		
		//search largest right
		for (int j = M - 1; j > i; j--){
			right = max(right, v[j]);
		}
		
		//calculate
		ans += max(0, min(left, right) - v[i]);
	}

	cout << ans;

	return 0;
}
















