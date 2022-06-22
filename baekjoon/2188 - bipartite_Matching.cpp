//https://m.blog.naver.com/ndb796/221241403806

#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define MAX 201

using namespace std;

int N, M, S;
vector<int> a[MAX];
bool finished[MAX];	//�̹� �� ��忡 ���� �۾��� �Ϸ��ߴ��� 
int d[MAX];			//(��Ʈ�� ����)�����ϰ� �ִ� ����� ������ ���� �� 

//if succeeded in matching, return TRUE, else FALSE
bool DFS(int cur){

	//��� ����� ��忡 �� �� �ִ��� �õ� (person 1 -> ��Ʈ�� A, B, C ����) 
	for (int i = 0; i < a[cur].size(); i++){
		int next = a[cur][i];
		
		//�̹� ó���� ���� �� �̻� �� �ʿ� ���� 
		if (finished[next] == true) continue;
		
		finished[next] = true;
		
		//������ �ȹ޾Ƽ� ����ְų� OR �ش� ��带  �����ϰ� �ִ� ������� �ٸ����� ���� �ִ��� ��� 
		//ex. 1�� ���(A,B,C ���� ����)�� A�� �����ߴµ�, 2�� ��尡 A�� ������ �� ������, 1������ ��� B�� ������ �� ������ TRUE! 
		if (d[next] == 0 || DFS(d[next])){
			d[next] = cur;	//���� ����ϰ� A�ϰ� match 
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












