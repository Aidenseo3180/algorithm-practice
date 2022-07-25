#include <iostream>

using namespace std;
#define MAX 401

const int INF = 999999;
int V, E, result = INF;
int arr[MAX][MAX];

int main() {
    cin >> V >> E;
    
    //�� ������ ǥ��
    for(int i=1;i<=V;i++)
        for(int j=1;j<=V;j++)
            arr[i][j]=INF;
            
    //�� ������ ǥ��
    for(int i=0;i<E;i++) {
        int x,y,z;
        cin >> x>> y >> z;
        arr[x][y] = z;
    }
    
    //�÷��̵� �ͼ�
    for(int k=1;k<=V;k++)  //k = ���İ��� ���
        for(int i=1;i<=V;i++)  // i = ��� ���
            for(int j=1; j<=V;j++)  // j = ���� ���
                if(arr[i][j] > arr[i][k] + arr[k][j]) //�� ���� ��
                    arr[i][j] = arr[i][k] + arr[k][j];
                    
    //�ٽ� ���������� ���ƿ� �� �� ���� ���� �� ����
    for(int i=1;i<=V;i++)
        result = min(result, arr[i][i]);
        
    //��� ���
    cout << ((result == INF) ? -1:result);
}















