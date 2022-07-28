//https://hagisilecoding.tistory.com/7
#include <iostream>
#include <algorithm>
#include <math.h>

#define endl "\n"

using namespace std;

int arr[500001];
double sum = 0;
int N;

void first(){
	
	int z = round(sum / double(N));
	if (z == -0) z = 0;		//NOTE : for some reason, it prints -0 instead of 0 -> so get rid of it using if statement
	
	cout << z << endl;
}

void second(){
	cout << arr[(N - 1) / 2] << endl;
}

void third(){
	
	int result;
    int count = 0;	//indicates if there's more than 1 numbers w/ same maximum cnt
    int cnt2[8001] = {0};
    
    for (int i = 0; i < N; i++){	//-4000 ~ 4000, +1 to corresponding number (index)
        cnt2[arr[i] + 4000]++;
    }
    
    int max_mode = *max_element(cnt2, cnt2 + 8001);	//find max element
    
    //search from -4000 ~ 4000 in order (b/c we want 2nd highest if there are more than 1 max)
    for (int i = 0; i < 8001; i++){	//start from 0 & -4000 from it (can also start from -4000 and go up to 4001)
        if(cnt2[i] == max_mode){	//if cnt == max cnt
            count++;
            result = i - 4000;
        }
        if(count == 2){	//if we have another 2nd number that has same maximum cnt, break -> print it
            break;
        }
    }
    
	cout << result << endl;
}

void fourth(){
	cout << arr[N - 1] - arr[0];
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> N;
		
	for (int i = 0; i < N; i++){
		cin >> arr[i];
		
		sum += arr[i];
	}

	sort(arr, arr + N);
		
	first();
	second();
	third();
	fourth();
			
	return 0;
}











