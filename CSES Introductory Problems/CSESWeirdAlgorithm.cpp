#include<bits/stdc++.h>

using namespace std;

int main(){
	long long int k;
	cin>>k;
	long long int n;
	long long int sum = 0;
	for(int i=0;i<k-1;i++)
	{
		cin >> n;
		sum += n;
	}
	n = (k*(k+1))/2;
	cout << n - sum << endl;
	return 0;
}