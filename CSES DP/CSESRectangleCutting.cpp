#include<bits/stdc++.h>

using namespace std;

#define ll            long long
#define pb            push_back
#define pob           pop_back
#define mp            make_pair
#define rep(i, a, b)  for(int i=a;i<b;++i)
#define repb(i, a, b) for(int i=a;i>b;--i)
#define endl          '\n'
#define mod           1000000007
#define INF           1e9

#define nax           505


void solve(){
  int a, b;
  cin >> a >> b;
  vector<vector<int>> dpGrid(nax, vector<int>(nax, INF));
  for(int i=1;i<nax;i++)
  {
    for(int j=1;j<nax;j++)
    {
        dpGrid[i][j] = INF;
    }
  }
  for(int i=1;i<nax;i++)
  {
    dpGrid[i][i] = 0;
  }

  for(int i=1;i<=a;i++)
  {
    for(int j=1;j<=b;j++)
    {
        for(int s=1; s<i; s++)
        {
            dpGrid[i][j] = min(dpGrid[i][j], dpGrid[s][j] + dpGrid[i-s][j]+1);
        }
        for(int h=1; h<j; h++)
        {
            dpGrid[i][j] = min(dpGrid[i][j], dpGrid[i][h] + dpGrid[i][j-h]+1);
        }
    }
  }
   cout << dpGrid[a][b] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}