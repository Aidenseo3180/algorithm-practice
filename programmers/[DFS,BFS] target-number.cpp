#include <iostream>
#include <vector>

using namespace std;

int total;

//sum : how it adds up over time
//index : numbers of times it runs
void DFS(vector<int> numbers, int target, int sum, int index){

	//if index reaches the limit
	if (index == numbers.size()){
		//if meets the goal
		if (sum == target) total++;
		
		return;	//return anyways, whether you've met the goal or not
	}
	
	//DFS to +/- to sum, run over
	DFS(numbers, target, sum + numbers[index], index + 1);
	DFS(numbers, target, sum - numbers[index], index + 1);
	
}

int solution(vector<int> numbers, int target) {
	
	//start from 0 sum, 0 index b/c we want +1, -1 start && increment index overtime
	DFS(numbers, target, 0, 0);
    
    return total;
}

//above is the required function for the submission
int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<int> s = {1, 1, 1, 1, 1};
	int k = 3;
	
	cout << solution(s, k);
}

