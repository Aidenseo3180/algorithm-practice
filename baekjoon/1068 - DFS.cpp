#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int N, E, ans = 0;
int root;
vector<int> v[51];

int solution(int x){
	
	//if meets deleting part	
	if (x == E) return - 1;
	
	//if that element doesn't have any child (meaning current node is leaf node)
	if (v[x].size() == 0){
		ans++;
		return 0;
	}
	
	for (int i = 0; i < v[x].size(); i++){
		
		int temp = solution(v[x][i]);
		
		//if deleting node is the only child node of parent node & if the parent node's size is 1 (number of child node)
		if (temp == -1 && v[x].size() == 1){
			ans++;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	int input;
	for (int i = 0; i < N; i++){	//i = index of node
		cin >> input;
		
		//if root
		if (input == -1){
			root = i;
		}
		
		v[input].push_back(i);
	}
	
	cin >> E;	// == i
	
	solution(root);
	
	cout << ans;
	
}	

