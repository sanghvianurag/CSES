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

#define nax           1e6


void solve(){
  string x, y;
  cin >> x >> y;
  int n = x.size();
  int m = y.size();
  vector<vector<int>> dpGrid(n+1, vector<int>(m+1, 0));
  int k = 0;
  for(int i=0;i<=m;i++)
  {
    dpGrid[0][i] = k;
    k++;
  }
  k = 0;
  for(int i=0;i<=n;i++)
  {
    dpGrid[i][0] = k;
    k++;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
        if(x[i-1] == y[j-1])
        {
            dpGrid[i][j] = min(min(dpGrid[i][j-1]+1, dpGrid[i-1][j]+1), dpGrid[i-1][j-1]);
        }
        else
        {
            dpGrid[i][j] = min(min(dpGrid[i][j-1]+1, dpGrid[i-1][j]+1), dpGrid[i-1][j-1] + 1);
        }
    }
  }
  cout << dpGrid[n][m] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}