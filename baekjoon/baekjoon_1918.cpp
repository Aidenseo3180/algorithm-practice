#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string s;
	stack<char> tt;	//stack
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		//cout << i << endl;
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			cout << s[i];
		}
		else{
			if (s[i] == '(')
				tt.push(s[i]);
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!tt.empty() && (tt.top() == '*' || tt.top() == '/'))
            	{
                    cout << tt.top();
                    tt.pop();
                }
				tt.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while(!tt.empty() && tt.top() != '(')
				{
					cout << tt.top();
					tt.pop();
				}
				tt.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while(!tt.empty() && tt.top() != '(')
				{
					cout << tt.top();
					tt.pop();
				}
				tt.pop();	//take out ( from stack
			}
		}	
	}
	while(!tt.empty()){
		cout << tt.top();
		tt.pop();
	}

	return 0;
}




