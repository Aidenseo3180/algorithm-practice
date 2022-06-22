//https://m.blog.naver.com/ndb796/221241403806

#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define MAX 201

using namespace std;

int N, M, S;
vector<int> a[MAX];
bool finished[MAX];	//이미 그 노드에 대한 작업을 완료했는지 
int d[MAX];			//(노트북 같이)점유하고 있는 노드의 정보가 여기 들어감 

//if succeeded in matching, return TRUE, else FALSE
bool DFS(int cur){

	//모든 연결된 노드에 들어갈 수 있는지 시도 (person 1 -> 노트북 A, B, C 같이) 
	for (int i = 0; i < a[cur].size(); i++){
		int next = a[cur][i];
		
		//이미 처리한 노드는 더 이상 볼 필요 없음 
		if (finished[next] == true) continue;
		
		finished[next] = true;
		
		//선택을 안받아서 비어있거나 OR 해당 노드를  점유하고 있는 노드한테 다른곳에 갈수 있는지 물어봄 
		//ex. 1번 노드(A,B,C 선택 가능)가 A를 선택했는데, 2번 노드가 A만 선택할 수 있으면, 1번노드는 대신 B를 선택할 수 있으니 TRUE! 
		if (d[next] == 0 || DFS(d[next])){
			d[next] = cur;	//현재 노드하고 A하고 match 
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	//input
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++){
		cin >> S;
		
		for (int j = 1; j <= S; j++){
			int input;
			cin >> input;
			a[i].push_back(input);
		}
	}
	
	//algorithm
	int cnt = 0;
	for (int i = 1; i <= N; i++){
		
		fill(finished, finished + MAX, false);
		
		if (DFS(i)){
			cnt++;
		}
	}
	
	//print
	cout << cnt;
	return 0;
}












