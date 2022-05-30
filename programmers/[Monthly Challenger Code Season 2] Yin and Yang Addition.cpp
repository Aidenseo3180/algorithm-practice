#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int ans = 0;
    
    for (int i = 0; i < absolutes.size(); i++){
    	
    	ans += (signs[i] ? absolutes[i] : (-1 * absolutes[i]));
	}
    
    return ans;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<int> a1 = {4,7,12};
	vector<bool> s1 = {true,false,true};
	
	vector<int> a2 = {1,2,3};
	vector<bool> s2 = {false,false,true};
	
	cout << solution(a1,s1) << endl;
	cout << solution(a2, s2);

}

