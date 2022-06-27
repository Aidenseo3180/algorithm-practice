//https://dongdd.tistory.com/107
//https://m.blog.naver.com/PostView.naver?blogId=ndb796&logNo=221234427842&targetKeyword=&targetRecommendationCode=1

#include <iostream>
#include <algorithm>
 
#define INF 987654321

using namespace std;

int vertex, edge;
int arr[101][101];
int from, to, weight;
 
void floyd_warshall() {
    for (int i = 1; i <= vertex; i++){             // ith vertex를 거치는 경우
        for (int j = 1; j <= vertex; j++){         // from vertex
            for (int k = 1; k <= vertex; k++){     // to vertex
                if (arr[j][i] != INF && arr[i][k] != INF){
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                }
            }
        }
    }
}
 
int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
    cin >> vertex >> edge;
    for (int i = 1; i <= vertex; i++) {        // vectex table 초기화
        for (int j = 1; j <= vertex; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < edge; i++) {    // from vertex에서 to vertex 입력, 가중치 입력
        cin >> from >> to >> weight;
        if (arr[from][to] > weight) 
            arr[from][to] = weight;
    }
    floyd_warshall();
    
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if ( i == j || arr[i][j] == INF)	//if INF, print 0
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}





