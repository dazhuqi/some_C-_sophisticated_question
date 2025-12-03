#include<bits/stdc++.h>
using namespace std;

int matrixDP(vector<int>& p)
{
	int n = p.size() - 1;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	
	for(int length = 2; length <= n; length++)
	{
		for(int i = 1; i <= n + 1 - length; i++)
		{
			int j = i + length - 1;
			dp[i][j] = INT_MAX;
			for(int k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i-1]*p[k]*p[j]);
			}
		}
	}
	
	return dp[1][n];
}

int main()
{
	int n;
	cin>>n;
	vector<int> p(n + 1, 0);
	for(int i = 0; i < p.size(); i++)
		cin>>p[i];
	cout<<matrixDP(p);
	return 0;
}