#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

//gcd = greastest common factor
long long gcd(int a, int b)
{
	long c;
	while (b != 0)
	{
		c = a % b;
		cout << "before - c : " << c << " a : " << a << " b : " << b << endl;
		a = b;
		b = c;
		
		cout << "after - c : " << c << " a : " << a << " b : " << b << endl;
	}
	
	cout << "result : " << a << endl;
	return a;
}

long long solution(int w,int h) {
    long long W = w;    
    long long H = h;
    //w * h - (w' + h' - 1)gcd -> w * h - (w + h - gcd)
    //w' = w / gcd, h' = h / gcd
    long long tmp=(w+h)-gcd(w,h);
    
    return (W*H)-tmp;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cout << solution(8, 12);
	
}	

