#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long int n;
    cin >> n;
	long long int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long long int moves = 0;
	for(int i=1;i<n;i++)
	{
		if(arr[i] < arr[i-1])
		{
			moves += abs(arr[i]-arr[i-1]);
			arr[i] = arr[i-1];
		}
	}
	cout << moves << endl;
	return 0;
}