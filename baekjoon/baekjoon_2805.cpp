#include <iostream>
#include <algorithm>
using namespace std;
long long p[1000001];	//bc 0 ~ 10...0
long long N, M, res;	//res = maximum length that we set to meet M

void log_max(long long lo, long long hi)
{
	if (lo > hi) return;	//
	long long mid = (lo + hi) / 2;	//find mid point
	long long sum = 0;	
	for (int i = 0; i < N; i++) {	//for loop N times (number of tree)
		if (p[i] > mid)		//if greater than mid point
			sum += (p[i] - mid);	//cut down the tree to midpoint (10 + 5 + 0 + 7 = 22)
	}
	//cout << "lo : " << lo << " hi : " << hi << " sum : " << sum << " res : " << res <<"\n";
	if (sum >= M) {	//if sum is >= the log that we wanted, increase midpoint by more than half
		if(res<mid) res = mid;	//maximum length to cut would be the midpoint
		log_max(mid + 1, hi);	//increase mid point
	}
	else log_max(lo, mid - 1);	//if not both cases, decrease midpoint by 1
}

int main()
{
	cin >> N >> M;	//number of trees, length of log to take
	for (int i = 0; i < N; i++)
		cin >> p[i];
	sort(p, p + N);	//sort them for the function 
	log_max(0, p[N-1]);	//p[n-1] is the maximum length of tree exist
	cout << res;
}




