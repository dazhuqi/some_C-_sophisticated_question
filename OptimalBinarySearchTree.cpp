#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<double> p(n + 1),q(n + 1);
	for(int i = 1; i <= n; i++) cin>>p[i];
	for(int i = 0; i <= n; i++) cin>>q[i];
	vector<vector<double>> e(n + 2, vector<double> (n + 2, 0));
	vector<vector<double>> w(n + 2, vector<double> (n + 2, 0));
	vector<vector<int>> root(n + 2, vector<int> (n + 2, 0));
	
	for(int i = 0; i <= n; i++)
	{
		e[i][i] = q[i];
		w[i][i] = q[i];
	}
	
	for(int len = 1; len <= n; len++)
	{
		for(int i = 0; i <= n - len; i++)
		{
			int j = i + len;
			e[i][j] = 1e18;
			
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			
			for(int r = i + 1; r <= j; r++)
			{
				double cost = e[i][r - 1] + e[r + 1][j] + w[i][j];
				if(cost < e[i][j])
				{
					e[i][j] = cost;
					root[i][j] = r;
				}
			}
		}
	}
	
	cout<<e[0][n]<<endl;
}