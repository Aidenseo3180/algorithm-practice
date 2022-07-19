#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n"

using namespace std;

int Vertex, Edges;

//get parent node
int getParent(int set[], int x){
	
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

//compare & combine into single smaller parent
void unionParent(int set[], int a, int b){
	a = getParent(set, a);
	b = getParent(set, b);
	
	if (a < b) set[b] = a;
	else set[a] = b;
}

//check if both has same parent
int find(int set[], int a, int b){
	a = getParent(set, a);
	b = getParent(set, b);
	
	if (a == b) return 1;
	return 0;
}

class Edge{
	public:
		int node[2];
		int distance;
		
		Edge(int a, int b, int cost){
			this->node[0] = a;
			this->node[1] = b;
			this->distance = cost;
		}
	
		bool operator < (Edge &edge){	//for sort function
			return this->distance < edge.distance;
		}
};

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> Vertex >> Edges;
	
	vector<Edge> v;

	for (int i = 0; i < Edges; i++){
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;
		
		v.push_back(Edge(node1, node2, cost));
	}

	sort(v.begin(), v.end());	//the sort function included in library uses <, since items are Edge objects, edge class's < operator gets called

	int set[Vertex];
	for (int i = 0; i < Vertex; i++){
		set[i] = i;		//table that checks for cycle
	}
	
	int sum = 0;
	
	for (int i = 0; i < v.size(); i++){
		
		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)){
		
			sum += v[i].distance;
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
			
		}
	}

	cout << sum;
	
	return 0;	
}
















