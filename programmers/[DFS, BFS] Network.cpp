#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>> &computers, int index){
	//if 0
	if (computers[index][index] == 0) return false; 
	
	computers[index][index] = 0;
	
	//repeat number of node times
	for (int a = 0; a < computers.size(); a++){
		//if connected node exists, recursion
		if (computers[index][a] == 1) DFS(computers, a);
	}
	return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++){
    	if (computers[i][i] == 1 && DFS(computers, i)){
    		answer++;
		}
	}
   
    return answer;
}

//above is the required function for the submission
int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int a = 3;
	vector<vector<int>> b = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
	
	cout << solution(a,b);

}

