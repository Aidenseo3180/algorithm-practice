#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

	for (int i = 0; i < numbers.size(); i++){
		for (int j = 0; j < numbers.size(); j++){
			
			if (i == j) continue;	//no overlap due to same index
			
			int sum = numbers[i] + numbers[j];
			if (count(answer.begin(), answer.end(), sum) == false){	//if doesn't exist in answer vector
				answer.push_back(sum);
			}
		}
	}
	sort(answer.begin(), answer.end());

    return answer;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<int> a1 = {2,1,3,4,1};
	vector<int> a2 = {5,0,2,7};
	
	vector<int> b1 = solution(a1);
	vector<int> b2 = solution(a2);
	
	for (int i = 0; i < b1.size(); i++){
		cout << b1[i] << " ";	
	}
	cout << endl;
	
	for (int i = 0; i < b2.size(); i++){
		cout << b2[i] << " ";
	}
}


