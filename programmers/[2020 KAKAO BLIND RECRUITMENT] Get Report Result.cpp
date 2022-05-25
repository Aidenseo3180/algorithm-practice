#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    // 결과 Vector를 0으로 초기화
    vector<int> answer(id_list.size(), 0);

    // 각 멤버의 index를 Map에 저장
    unordered_map<string, int> id_idx_map;

    // [신고된 ID, 신고한 ID]를 저장할 Map 생성
    unordered_map<string, set<string>> report_map;

    // 각 멤버의 index를 Map에 저장
    for (auto i=0; i<id_list.size(); ++i){
        id_idx_map[id_list[i]] = i;
    }

    // [신고된ID, 신고한ID]를 Map에 저장
    for (auto rep : report){

        // 문자열 형태의 각 신고 정보를 parsing
        stringstream ss(rep);
        string from, to;	//from : 신고한 ID, to : 신고된 ID 
        ss >> from >> to;

        // [신고된ID, 신고한ID] 형태로 Map에 저장
        // report_map의 Value는 Set 형태이므로, 바로 insert 가능
        report_map[to].insert(from);
        
        //각각 한개의 신고된 ID에 tree로 된 신고한 ID들이 있음 
        //이런 신고한 ID들은 overlap이 안됨 (set라서, 한사람이 같은 사람을 2번 신고 못함)
		//이 tree의 사이즈가 총 몇명이 신고한 수 
        
    }

    // report_map을 탐색하며, 신고한ID의 개수가 K개 이상일 경우, 신고한ID들의 메일수를 +1
    for (auto iter : report_map){
        if (iter.second.size() >= k){
            for (auto in_iter : iter.second){
                answer[id_idx_map[in_iter]]++;
            }
        }
    }

    return answer;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<string> s = {"muzi", "frodo", "apeach", "neo"};
	vector<string> r = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
	vector<int> ans;
	ans = solution(s, r, 2);

	for (auto a : ans){
		cout << a << " ";
	}
}


