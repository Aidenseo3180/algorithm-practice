#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

#define INF 9999

using namespace std;

int start, V, E;

vector<pair<int,int>> vertex[10001];	//stores info of each node
int d[10001];	//shortest path table

//initialize shortest path table with INF
void initialize(){
	
	for (int i = 0; i < E; i++){
		d[i] = INF;
	}
}

void Djikstra(){
	
	priority_queue<pair<int,int>> pq;
	pq.push({0, start});	//d ��, ���� ���� (�����̴ϱ� start) 
	d[start] = 0;
	
	while(!pq.empty()){
		
		int cost = -pq.top().first;	//�湮�� ���� d �� 
		//top()�ϸ� queue tree�� ���� ����(root)�� ������ 
		//-�ϴ� ������ �ּ����� ���Ϸ���! priority queue�� ���� ���� ���� �� ���� ��. ������ -�� �ϸ� ���� ���� (-1 ���� ����) ���� tree�� ������ ��! 
		
		int cur = pq.top().second;	//���� �湮�� ���� 
		pq.pop();
		
		for (int i = 0; i < vertex[cur].size(); i++){	//���� �湮�� ���� ���� ���� 
			
			int next = vertex[cur][i].first;		//������ ���� ���� 
			int next_cost = cost + vertex[cur][i].second;	//���� ������ ���ļ� ���� ������ ���� ��� 
			
			//cout << next << " " << next_cost << " " << d[next] << "\n"; 
			if (next_cost < d[next]){	//���� ��뺸�� ���� �湮�� ������ ��ģ ����� �� �θ� 
				d[next] = next_cost;		//���� (shortest path table�� ������Ʈ) 
				pq.push({-next_cost, next});		//pq�� ���� 
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> V >> E; 	//����, ���� 
	
	// ��� ���� ������ �Է¹ޱ�
    for (int i = 0; i < E; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        // from ��忡�� to ���� ���� ����� cost ��� �ǹ�
        
		//����� �׷��� 
		vertex[from].push_back({to, cost});
        vertex[to].push_back({from, cost});
    }
	
	initialize();
	Djikstra();
	
	cout << "result : \n";
	for (int i = 0; i < V; i++){
		if (d[i] == INF){
			cout << "From 0 to " << i << " : INF\n";
		}
		else cout << "From 0 to " << i << " : " << d[i] << "\n";
	}

}

