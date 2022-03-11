#include <iostream>
using namespace std;
#define N 105
int a[N];
int dp[N][N]; // 前i个数分为j段所得最大
int sum[N];

/*
* 思路：建立两个数组dp和sum，其中：
* dp[i][j]为前i个数分为j段时，最大的分值和
* sum[i]为前i个数的和
*/

/*
* int getMaxSeg(int a[], int p, int m, int n)
* @param a: 输入的数组
* @param p: 模数
* @param m: 要分的段数
* @param n: 数组长度
* @return: 最大分值和
*/
int getMaxSeg(int a[], int p, int m, int n)
{
	// 初始化
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
