#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int answer = 50;
bool visited[50];

//find number of different letters
bool find_diff(string a, string b){
	int cnt = 0;
	
	for (int i = 0; i < a.length(); i++){
		if (a[i] != b[i])
			cnt++;
	}
	
	if (cnt == 1)
		return true;
	
	return false;
}

void DFS(string current, string target, vector<string> words, int step){
	
	//if step is higher than answer (since we want minimum, just ignore)
	if (answer <= step){
		return;
	}
	
	//if we found the target
	if (current == target){
		//compare and set minimum 
		answer = min(answer, step);
		return;
	}
	
	for (int i = 0; i < words.size(); i++){
		if (find_diff(current, words[i]) && !visited[i]){
			visited[i] = true;
			
			DFS(words[i], target, words, step + 1);
			
			//backtracking, once dfs ends, set visited to false to revisit from other branches
			visited[i] = false;
		}	
	}
}

//only can change one letter at a time
int solution(string begin, string target, vector<string> words) {
   
	DFS(begin, target, words, 0);  
   
   //if we haven't found anything (answer = 50 in the beginning),
   if (answer == 50){
		return 0;
   }
   
   return answer;
}

//above is the required function for the submission
int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<string> str = {"hot", "dot", "dog", "lot", "log", "cog"};
	
	cout << solution("hit", "cog", str);
	
}

