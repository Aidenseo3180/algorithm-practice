#include <iostream>
#include <stack>
#include <string>

#define endl "\n"

using namespace std;

bool solution(string s)
{
    bool answer;

	stack<char> st;

	for (int i = 0; i < s.size(); i++){	//for each index of string
		if (st.empty()) st.push(s[i]);	//if stack is empty, add one from string
		else{
			char cur = st.top();
			if (cur == '(' && s[i] != cur){	//if top of stack is '(' & incoming string is not '(', then pop
				st.pop();
			}
			else{
				st.push(s[i]);
			}
		}
	}
	
	answer = st.empty();	//if stack is empty, return 1 b/c everything worked

    return answer;
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cout << solution("(()(");
	
	return 0;
}











