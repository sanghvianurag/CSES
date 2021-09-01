#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	char t = s[0];
	int count = 1;
	int i = 1;
	int ans = 1;
	while(i < s.size())
	{
		if(s[i] == t)
		{
			count++;
			ans = max(ans, count);
		}
		else
		{
			count = 1;
			t = s[i];
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}