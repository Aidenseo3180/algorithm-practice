#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    // ��� Vector�� 0���� �ʱ�ȭ
    vector<int> answer(id_list.size(), 0);

    // �� ����� index�� Map�� ����
    unordered_map<string, int> id_idx_map;

    // [�Ű�� ID, �Ű��� ID]�� ������ Map ����
    unordered_map<string, set<string>> report_map;

    // �� ����� index�� Map�� ����
    for (auto i=0; i<id_list.size(); ++i){
        id_idx_map[id_list[i]] = i;
    }

    // [�Ű��ID, �Ű���ID]�� Map�� ����
    for (auto rep : report){

        // ���ڿ� ������ �� �Ű� ������ parsing
        stringstream ss(rep);
        string from, to;	//from : �Ű��� ID, to : �Ű�� ID 
        ss >> from >> to;

        // [�Ű��ID, �Ű���ID] ���·� Map�� ����
        // report_map�� Value�� Set �����̹Ƿ�, �ٷ� insert ����
        report_map[to].insert(from);
        
        //���� �Ѱ��� �Ű�� ID�� tree�� �� �Ű��� ID���� ���� 
        //�̷� �Ű��� ID���� overlap�� �ȵ� (set��, �ѻ���� ���� ����� 2�� �Ű� ����)
		//�� tree�� ����� �� ����� �Ű��� �� 
        
    }

    // report_map�� Ž���ϸ�, �Ű���ID�� ������ K�� �̻��� ���, �Ű���ID���� ���ϼ��� +1
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


