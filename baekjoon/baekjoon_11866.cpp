#include <iostream>
#include <queue>
using namespace std;

int h, k;
queue<int> q;

int main()
{
	//h : number of elements k : index
	cin >> h >> k;
	
	for (int i = 1; i <= h; i++){
		q.push(i);
	}
	cout << "<";
	while (1){
		//for loop to put front element to back k-1 times.
		for (int i = 1; i < k; i++){
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		
		q.pop();
		
		//when it's not empty, put colon
		if (!q.empty())	cout << ", ";
		else break;
		
	}
	cout << ">";
	
}














