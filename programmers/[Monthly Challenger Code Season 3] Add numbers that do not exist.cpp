#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n"

using namespace std;

int solution(vector<int> num) {

	sort(num.begin(), num.end());

    int ans = 0;
    int cnt = 0;
    
    for (int i = 0; i < 10; i++){
    	if (i != num[cnt]){
    		ans += i;
		}
		else{
			cnt++;
		}
	}
    
    return ans;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<int> a = {1,2,3,4,6,7,8,0};
	vector<int> b = {5,8,4,0,6,7,9};
	
	cout << solution(a) << endl;
	cout << solution(b);

}

