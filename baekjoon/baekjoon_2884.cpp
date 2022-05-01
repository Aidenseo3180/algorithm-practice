#include <iostream>

using namespace std;

int main(){
	
	int hour, min;
	int time = 45;
	
	cin >> hour >> min;
	
	time = min - time;
	
	//if min is less than 45 (time is negative now)
	if (time < 0){
		hour--;
		if (hour < 0){
			hour = 23;
		}
		
		min = 60 + time;	//so add to subtract from 60
	}
	else{
		min = time;
	}
	
	cout << hour << " " << min;
	
}
