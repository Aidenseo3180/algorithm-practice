#include <iostream>

using namespace std;

int n, x, y;
int arr[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int count = 0;
	cin >> n;
	
	//decrement n over time
	while(n--){
		cin >> x >> y;
		
		for (int i = x; i < x + 10; i++){
			for (int j = y; j < y + 10; j++){
				//if other than 0 (empty), than fill it with 1 & count up
				if (!arr[i][j]){
					arr[i][j] = 1;
					count++;
				}	
			}
		}
	}
	
	cout << count;
	
}














