#include <iostream>
using namespace std;
#define N 105
int a[N];
int dp[N][N]; // ǰi������Ϊj���������
int sum[N];

/*
* ˼·��������������dp��sum�����У�
* dp[i][j]Ϊǰi������Ϊj��ʱ�����ķ�ֵ��
* sum[i]Ϊǰi�����ĺ�
*/

/*
* int getMaxSeg(int a[], int p, int m, int n)
* @param a: ���������
* @param p: ģ��
* @param m: Ҫ�ֵĶ���
* @param n: ���鳤��
* @return: ����ֵ��
*/
int getMaxSeg(int a[], int p, int m, int n)
{
	// ��ʼ��
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = (dp[i - 1][1] + a[i]) % p;
		sum[i] = sum[i - 1] + a[i];
	}

	for (int j = 2; j <= m; j++)
	{
		for (int i = j; i <= n; i++)
		{
			int mx = -1;
			for (int k = j - 1; k < i; k++)
				mx = max(mx, dp[k][j - 1] + (sum[i] - sum[k]) % p);
			dp[i][j] = mx;
		}
	}

	return dp[n][m];
}

int main()
{
	int p, m, n;
	cin >> p >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << getMaxSeg(a, p, m, n);
}
