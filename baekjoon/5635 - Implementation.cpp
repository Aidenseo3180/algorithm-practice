#include <iostream>
#include <string>

#define endl "\n"

using namespace std;

int N;
int min_val = 1e9;
string min_name;
int max_val = 0;
string max_name;

string arr[100][2];

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++){
		string name, day, month, year;
		
		cin >> name >> day >> month >> year;
		
		if (day.length() == 1) day.insert(0, "0");
		if (month.length() == 1) month.insert(0, "0");
		
		arr[i][0] = name;
		arr[i][1] = year + month + day;	//add year, month, day & compare which one's biggest
	}

	for (int i = 0; i < N; i++){
		int value = stoi(arr[i][1]);
		
		if (value < min_val){
			min_val = value;
			min_name = arr[i][0];
		}
		
		if (value > max_val){
			max_val = value;
			max_name = arr[i][0];
		}
		
		//cout << arr[i][1] << endl;
	}

	cout << max_name << "\n" << min_name;
	
	return 0;
}
















