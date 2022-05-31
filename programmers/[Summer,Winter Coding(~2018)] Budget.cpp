#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++){
    	
    	if ((budget - d[i]) >= 0){
    		budget -= d[i];
    		answer++;
		}
		else break;
	}
    
    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<int> d1 = {1,3,2,5,4};
	vector<int> d2 = {2,2,3,3};
	
	cout << solution(d1, 9) << endl;
	cout << solution(d2, 10);

}










