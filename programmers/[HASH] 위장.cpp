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
    
    //������. 
    for (iter = map.begin(); iter != map.end(); iter++){
    	answer *= (iter -> second + 1);	//type + no selection. ex) ���׶� �Ȱ�, ���۶�, �� ���þ��� <- �̷��� +1�� ���þ����� �������� �� type���� �� 
	}
    
    return answer - 1;	//-1 for not wearing any clothes (���� ���þ��� �̶� �������� ����. ������ ���� �԰� �־�� �ϴϱ�)
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<vector<string>> c = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
	
	cout << solution(c);
	
}


