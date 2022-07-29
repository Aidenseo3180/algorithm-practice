//got help for string input part in beginning : https://ongveloper.tistory.com/115
#include <iostream>
#include <algorithm>
#include <deque>
#include <sstream>
#include <string>

#define endl "\n"

using namespace std;

int T, n, error_flag = 0, read_d = 0;	//0 : read from front, 1 : read from back
string p, s;

void print(deque<int> dq){
	
	cout << "[";
	if (read_d == 0){
		for (int i = 0; i < dq.size(); i++){
			cout << dq[i];
			if (i != dq.size() - 1){
				cout << ",";
			}
		}
	}
	else if (read_d == 1){
		for (int i = dq.size() - 1; i >= 0; i--){
			cout << dq[i];
			if (i != 0){
				cout << ",";
			}
		}
	}
	cout << "]" << endl;
	
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while(T--){
		deque<int> dq;
		read_d = 0;	//set to front by default
		error_flag = 0;
		
		cin >> p;
		cin >> n;
		cin >> s;
		
		string str = "";
		for (int i = 0; i < s.length(); i++){
			
			if (isdigit(s[i])){
				str += s[i];
			}
			else{	//if not digit, add to deque
				if (!str.empty()){
					dq.push_back(stoi(str));	//string -> int
					str = "";	
				}
			}
		}
		
		for (int i = 0; i < p.length(); i++){
			//flip direction when R
			if (p[i] == 'R'){
				if (read_d == 1) read_d = 0;
				else read_d = 1;
			}
			//pop item (depends on current direction)
			else{	//if D
				if (dq.empty()){
					cout << "error" << endl;
					error_flag = 1;
					break;
				}
				if (read_d == 0){	//if read from front
					dq.pop_front();
				}
				else if (read_d == 1){	//if read from back
					dq.pop_back();
				}
			}
		}
		
		if (error_flag == 1) continue;
		
		//printing
		print(dq);
		
	}
	
	return 0;
}











