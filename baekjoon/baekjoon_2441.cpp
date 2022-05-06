#include<iostream>
#include <vector>

using namespace std;

int N;

void func(int N){
	
	vector<char> star;
	
	for (int i = 0; i < N; i++){
		star.push_back('*');
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << star[j];
		}
		cout << "\n";
		star[i]= ' ';
	}
	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   	cin >> N;
   
   	func(N);
   
    return 0;
}














