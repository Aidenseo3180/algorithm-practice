#include <iostream>

using namespace std;

int N, M;	//N : number range, M : size of array
int arr[9];
int visited[9];

void solution( int depth ){
	
	//base case
	if (depth == M){
		for (int i = 0; i < M; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = 1; i <= N; i++){
		if (!visited[i]){	//if we haven't visited this number
			//set array at current index as i
			arr[depth] = i;
			visited[i] = 1;
			//and call recursive function w/ depth + 1
			solution(depth + 1);				
			visited[i] = 0;	//backtracking
		}
	}
}

//above is the required function for the submission
int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	solution(0);
	
}
















