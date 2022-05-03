#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<pair<int, char>> v;	//int : key, char : value
	unsigned int n1, n2, num;
	cin >> n1 >> n2;
	
	string str;
	cin >> str;
	for (int i = n1-1 ; i >= 0; i--){	//to prevent overlapping, treat key like a value
		v.push_back({str[i], 0});	//0 : move to right
	}
	
	cin >> str;
	for (int i = 0; i < n2; i++){
		v.push_back({str[i],1});	//1 : move to left
	}
	
	cin >> num;
	unsigned int t = 0;
	
	//if one group moves to right, then the other group doesn't need to move to the left
	while(t != num){
		for (int i = 0; i < (n1 + n2 - 1); i++){	//n1 + n2 - 1 because it won't reach the end (if there are 6 elements, run only 5 times)
			//if key in front is different then
			if (v[i].second == 0 && v[i+1].second == 1){
				swap(v[i], v[i+1]);
				i++;	//if swap happens, move 2 blocks ahead (otherwise, iterate 1)
			}
		}
		t++;	//number of runs	
	}
	
	for (int i = 0; i < (n1+n2); i++){
		cout << char(v[i].first);
	}

}





