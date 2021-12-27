#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	
	while(q.size() != 1){
		q.pop();	//take out the first element
		q.push(q.front());	//push the second element
		q.pop();	//take out the second element
	}
	
	cout << q.front();
	
	return 0;
}




