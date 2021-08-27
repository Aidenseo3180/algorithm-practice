#include <iostream>
#include <bits/stdc++.h>
#include<windows.h>

//https://www.acmicpc.net/problem/4948
using namespace std;

int main(){
	
	int input;			//user input
	while (true){
		cin >> input;
		if (input == 0){	//user can type 0 to end the program
			break;
		}
		int isPrime = 0;  	//number of primes 
		int count = 0;		//count how many times the number can be divided
		int a = input;
		
		while (a < (2*input)+1){	//a =< input =< 2a
			for (int i = 1; i < a+1; i++){
				int result = a % i;		//1%1, 2%1, 2%2, 3%1, ...
				if (result == 0){		//when the number gets divided by i,  result becomes 0
					count = count + 1;	//this should be 2 always, in order to be a prime number ( 1 and itself)
				}
			}
			if (count == 2){			//when there's only 2 counts (divided by itself, and 1)
				isPrime = isPrime + 1;	//inc the number of prime number in a range of input
			}
			count = 0;	//reset count (reset at the end of for loop for another round of while loop)
			a = a + 1;	//increment n
			
		}
		cout << isPrime << endl;
		
	}
	return 0;
}



