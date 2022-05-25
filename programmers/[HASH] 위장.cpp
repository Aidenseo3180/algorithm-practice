#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> map;	//type, number of that type of clothes
    
    for (vector<string> c : clothes){
    	map[c[1]]++;	//count up same type of clothes
	}
    
    unordered_map<string, int> :: iterator iter;
    
    //곱연산. 
    for (iter = map.begin(); iter != map.end(); iter++){
    	answer *= (iter -> second + 1);	//type + no selection. ex) 동그란 안경, 선글라스, 얼굴 선택안함 <- 이렇게 +1로 선택안함의 선택지를 각 type마다 줌 
	}
    
    return answer - 1;	//-1 for not wearing any clothes (모든걸 선택안함 이란 선택지를 없앰. 무조건 무언갈 입고 있어야 하니까)
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<vector<string>> c = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
	
	cout << solution(c);
	
}


