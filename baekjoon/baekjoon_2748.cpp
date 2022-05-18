#include <iostream>

using namespace std;

int N;
long long mem[91];

long long fibonacci(int x){
	
	if (x <= 1) return x;
	
	if (mem[x]!= 0) return mem[x];
	
	mem[x] = fibonacci(x - 1) + fibonacci(x - 2);
	
	return mem[x];
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	cout << fibonacci(N);
	
	return 0;	
}


















