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

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<long long> numberOfCoins(x+1, 0);
    numberOfCoins[0] = 1;
    for(int j=0;j<coins.size();j++)
    {
        for(int value = 1; value<=x; value++)
        {
            if(value - coins[j] >= 0)
            {
                numberOfCoins[value] += numberOfCoins[value-coins[j]]%mod;
            }
        }
    }
    cout << numberOfCoins[x]%mod << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}