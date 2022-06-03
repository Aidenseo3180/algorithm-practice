#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define endl "\n"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	while(1){
		int N, zero = 0;
		vector<int> v;
		
		cin >> N;
		if (N == 0) break;	
		
		for (int i = 0; i < N; i++){
			int input;
			cin >> input;
			
			if (input == 0) zero++;
			v.push_back(input);
		}
		
		//sort in ascending order (all the zeros are in the front)
		sort(v.begin(), v.end());
		
		// 0 1 2 3 -> 2 1 0 3 (so that 0 doesn't come front of vector)
		if (zero == 1){
			swap(v[0], v[2]);
		}
		//if more than 2,
		//ex. 00001234 -> 12000034 -> 1003 + 2004
		if (zero >= 2){
			swap(v[0], v[zero]);
			swap(v[1], v[zero + 1]);
		}
		
		string a = "", b = "";
		for (int i = 0; i < v.size(); i++){
			
			string str = to_string(v[i]);
			if (i % 2 == 0) a += str;
			else b += str;
		}
		//cout << a << " + " << b;
		cout << stoi(a) + stoi(b) << endl;
	}

}










