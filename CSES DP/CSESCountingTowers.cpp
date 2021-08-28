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
  vector<vector<ll>> dpGrid(nax, vector<ll>(8, 0));
  for(int i=0;i<8;i++)
  {
    dpGrid[0][i] = 1;
  }
  for(int i=1;i < nax; i++)
  {
    for(int j=0;j<8;j++)
    {
        if(j == 0 || j== 2 || j==3 || j == 4 || j == 5)
        {
            dpGrid[i][j] = (dpGrid[i-1][0] + dpGrid[i-1][1] + dpGrid[i-1][3] + dpGrid[i-1][4] + dpGrid[i-1][5])%mod;
        }
        else
        {
            dpGrid[i][j] = (dpGrid[i-1][2] + dpGrid[i-1][6] + dpGrid[i-1][7])%mod;
        }
    }
  }
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    cout << (dpGrid[n-1][2] + dpGrid[n-1][6])%mod << endl;
  }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}