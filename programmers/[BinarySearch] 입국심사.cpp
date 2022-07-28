//설명 : https://0xd00d00.github.io/2021/06/29/programmers_entry_test.html
//좀더 디테일한 설명 : https://hochoon-dev.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%9E%85%EA%B5%AD%EC%8B%AC%EC%82%AC-c
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

// n = 기다리는 사람 수
// times = 심사하는데 걸리는 시간
// times.size() = 심사관수
long long solution(int n, vector<int> times){
	
    long long answer = 0;
    sort(times.begin(), times.end());	//sort in ascending order (highest time is in the end)

    long long start = 1;	//min 
    long long end = (long long) times[times.size()-1] * n;	//max, if 10 is highest, 10 * 6 (number of ppl waiting) = 60min -> maximum time it can take up to
    long long mid;

    while(start <= end) {
        mid = (start + end) / 2;	//average
        long long cnt = 0;

        for(int i = 0; i < times.size(); i++) {
        	//각 시간별 mid시간동안 처리할 수 있는 사람들 수 더함 
        	//binary Search 사용하는 이유 : mid (반)을 기준으로 계산하니까, 반은 7에서 처리, 또다른 반은 10에서 처리 -> 둘다 같은 cnt에 더함 
            cnt += mid / times[i];
            
        }

		//만약 처리할 수 있는 수 < 기다리는 사람이면 start (lelft), 최소값을 바꿈 
        if(cnt < n) {
            start = mid + 1;
        }
        
        //if we can deal w/ all the ppl 
        else {
        	//if mid(avg) is lower than end(max)
        	//mid can be the mininmum value, so put into answer
            if(mid <= end) {
                answer = mid;
            }
            //to find minimum, shrink end (right)
            end = mid - 1;
        }
    }

    return answer;
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<int> v = {7, 10};
	cout << solution(6, v);

	
	return 0;
}











