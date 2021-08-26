/*
https://www.acmicpc.net/problem/2920
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

int data[8];
bool asc = true;
bool des = true;

int main(){
	for (int i = 0; i<8; i++){
		std::cin >> data[i];
	}
	for (int i = 1; i < 8; i++){	//check from index 1, so that we can check i-1
		if (data[i] > data[i-1]){
			des = false;
		}
		if (data[i] < data[i-1]){ 
			asc = false;
		}
	}
	if (asc)
		std::cout << "ascending";
	else if (des)
		std::cout << "descending";
	else
		std::cout << "mixed";
	
	return 0;
}


