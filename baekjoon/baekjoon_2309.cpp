//problem : https://www.acmicpc.net/problem/2309
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	int input;		//input
	int sum = 0;	//sum of heights. Must be 100
	
	vector<int> vec;
	vector<int> result;	//stores correct vectors
	for (int i = 0; i<9; i++){
		cin >> input;
		vec.push_back(input);
	}
	sort(vec.begin(), vec.end());
	
	//iterators
	vector<int>::iterator iter;
	vector<int>::iterator it;
	
	for (iter = vec.begin(); iter != (vec.end()); iter++){	//each one of vec element
		for (it= vec.begin(); it!= (vec.end()-1); it++){  	//exclude the highest number (bc we know that it wouldnt lead to 100)
			if (*iter != *it){
				sum = sum + *it;
				result.push_back(*it);	//add to result vector array
				if (sum == 100){
					goto end;	//break
				}
			}
		}
		result.clear();	//if sum !=100, then clear the result, and try again
		sum = 0;	//reset sum every for loop
	}
	
	end:
		vector<int>::iterator it_end;	//print out result vector array
		for (it_end = result.begin(); it_end != result.end(); it_end++){
			cout << *it_end << endl;
		}	
	
	return 0;
}



