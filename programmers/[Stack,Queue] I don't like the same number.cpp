#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define endl "\n"

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    
    st.push(arr[arr.size() - 1]);	//put last element of arr to stack
    for (int i = arr.size() - 2; i >= 0; i--){	//start from last - 1
    	if (st.top() != arr[i]){	//compare, if different, put into stack
    		st.push(arr[i]);
		}
	}

	while(!st.empty()){
		answer.push_back(st.top());	//put stack elements into answer vector
		st.pop();
	}

    return answer;
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<int> s = {4,4,4,3,3};
	vector<int> ans = solution(s);
	
	for (auto iter : ans){
		cout << iter << " ";
	}
	
	return 0;
}


//alternative way :

vector<int> solution(vector<int> arr) 
{
   	
   	arr.erase(unique(arr.begin(), arr.end()), arr.end());	//unique : removes all the consecutive duplicate elements from array / vector, returns iterator, O(n) speed
   	
   	vector<int> answer = arr;
   	
    return answer;
}











