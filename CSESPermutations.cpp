#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long int n;
    cin >> n;
    if(n < 4)
    {
    	if( n == 1)
    	{
    		cout << 1 << endl;
    	}
    	else
    	{
    		cout << "NO SOLUTION" << endl;
    	}
    }
    else if(n == 4)
    {
    	vector<int> ans = {2, 4, 1, 3};
    	for(auto x: ans)
    	{
    		cout << x << " ";
    	}
    }
    else
    {
    	vector<int> odd;
		vector<int> even;
		for(int i=1;i<=n;i++)
		{
			if(i%2==0)
			{
				even.push_back(i);
			}
			else
			{
				odd.push_back(i);
			}	
		}
		for(auto x: odd)
		{
			cout << x << " ";
		}
		for(auto x: even)
		{
			cout << x << " ";
		}
	}
	
	return 0;
}