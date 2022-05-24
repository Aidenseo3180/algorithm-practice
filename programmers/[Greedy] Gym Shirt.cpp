#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> shirt(n, 1);
    
    //-1 for lost students
    for (auto a : lost) shirt[a - 1]--;	//since student 1 ~ 5, 1-1 = 0 index : 1st student
    //+1 for students w/ extra
    for (auto b : reserve) shirt[b - 1]++;
    
    for (int i = 0; i < shirt.size(); i++){
    	//if doesn't have a t-shirt
		if (shirt[i] == 0){
    		//check right
    		if (i != shirt.size() - 1 && shirt[i + 1] == 2){
    			shirt[i + 1]--;
				shirt[i]++;
			}
    		//check left
    		else if (i && shirt[i - 1] == 2){
    			shirt[i - 1]--;
    			shirt[i]++;
			}	
		}
	}
    
    for (auto c : shirt){
    	if (c != 0) answer++;
	}
    
	return answer;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<int> l = {2, 4};
	vector<int> r = {1, 3, 5};
	cout << solution(5, l, r);
	
}

