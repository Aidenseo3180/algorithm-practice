#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> vec = {	//coordinate of 0 ~ 9 from keypad
	{3,1}, {0,0}, {0,1}, {0,2},
	{1,0}, {1,1}, {1,2}, 
	{2,0}, {2,1}, {2,2},
	{3,0}, {3,2}
};

string solution(vector<int> num, string hand) {	//what to press, which hand you use the most
    
    int L = 10, R = 11;
    int L_diff, R_diff;
    string ans = "";
    
    //num[i] = next button to press
    for (int i = 0; i < num.size(); i++){
    	
    	if (num[i] == 1 || num[i] == 4 || num[i] == 7){
    		L = num[i];
    		ans += "L";
		}	
		else if (num[i] == 3 || num[i] == 6 || num[i] == 9){
			R = num[i];
			ans += "R";
		}	
		else{
			//use manhattan shortest path formula (need x and y values)
			//abs(x1 - x2) + abs(y1 - y1) <- order of x1 and x2 doesn't matter
			//(x of keypad alreayd pressed by L - x of next keypad) + (...)
			L_diff = abs(vec[L].first - vec[num[i]].first) + abs(vec[L].second - vec[num[i]].second);
			R_diff = abs(vec[R].first - vec[num[i]].first) + abs(vec[R].second - vec[num[i]].second);
			
			//lowest difference = closest 
			if (L_diff == R_diff){
				if (hand == "left"){
					L = num[i];
					ans += "L";
				}	
				else if (hand == "right"){
					R = num[i];
					ans += "R";
				}
			}
			else if (L_diff < R_diff){
				L = num[i];
				ans += "L";
			}
			else if (R_diff < L_diff){
				R = num[i];				
				ans += "R";
			}
		}
	}
    
    return ans;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<int> n1 = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
	vector<int> n2 = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
	vector<int> n3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	
	cout << solution(n1, "right") << "\n";
	cout << solution(n2, "left") << "\n";
	cout << solution(n3, "right") << "\n";
	
}















