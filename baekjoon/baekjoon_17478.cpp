#include<iostream>

using namespace std;

int N;
string s[51];

void recursion(int x){

	for (int i = 0; i < x*4; i++){
		s[x] = s[x] + "_";
	}
	
	cout << s[x] << "\"����Լ��� ������?\"" << endl;		
	
	//base cae
	if (x == N){
		cout << s[x] << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		cout << s[x] << "��� �亯�Ͽ���." << endl;

		return;
	}
	else{
		cout << s[x] << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
		cout << s[x] << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
		cout << s[x] << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
	}
	
	x++;
	recursion(x);
	x--;
	cout << s[x] << "��� �亯�Ͽ���." << endl;
	
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
    
    recursion(0);
    
    return 0;
}














