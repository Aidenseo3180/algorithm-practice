//https://mungto.tistory.com/37
#include <iostream>
#include <stack>
#include <string>

#define endl "\n"

using namespace std;

int solution(string s)
{
    int answer = 0;
	
	stack<char> st;
	
	for (int i = 0; i < s.length(); i++){
		if (st.empty() || st.top() != s[i]) st.push(s[i]);	
		else if (st.top() == s[i]) st.pop();
	}
	
	if (st.empty() == true) answer = 1;

    return answer;
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cout << solution("cdcd");

	return 0;
}
















