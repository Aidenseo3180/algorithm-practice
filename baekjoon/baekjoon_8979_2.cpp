#include <iostream>

using namespace std;

int N, K, ans = 1;
int index;
int gold[1001], silver[1001], bronze[1001];

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	
	for (int i = 0; i < N; i++){
		cin >> index;
		cin >> gold[index] >> silver[index] >> bronze[index];
	}
	
	for (int i = 1; i <= N; i++){
		
		if (gold[i] > gold[K]){
			ans++;
		}
		else if (gold[i] == gold[K]){
			if (silver[i] > silver[K]){
				ans++;
			}
			else if (silver[i] == silver[K]){
				if (bronze[i] > bronze[K]){
					ans++;
				}
			}
		}
	}
	cout << ans;
}



















