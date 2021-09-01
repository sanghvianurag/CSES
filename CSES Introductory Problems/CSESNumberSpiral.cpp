#include<bits/stdc++.h>

using namespace std;

long long solve(long long x, long long y)
{
	long long mx = max(x, y);
	if(mx%2 == 0)
	{
		if(y == 1)
		{
			return mx*mx;
		}
		else if( x < mx)
		{
			return solve(mx,mx) - (mx-x);
		}
		else if( x == mx)
		{
			return ((mx*mx) - (y-1));
		}
	}
	else
	{
		if(x == 1)
		{
			return mx*mx;
		}
		else if(y < mx)
		{
			return solve(mx,mx) - (mx - y);
		}
		else if(y == mx)
		{
			return (mx*mx) - (x-1);
		}
	}
	return 0;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		long long x, y;
		cin >> x >> y;
		cout << solve(x, y) << "\n";
	}
}