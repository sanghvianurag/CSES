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
    int n;
    cin >> n;
    vector<int> minDigits(n+1, INF);
    minDigits[0] = 0;
    for(int i=1; i <= 9; i++)
    {
       minDigits[i] = 1;
    }
    if(n < 10)
    {
        cout << minDigits[n] << endl;
    }
    else
    {
        for(int value = 10; value <= n; value++)
        {
            vector<int> possibleDigits;
            int holder = value;
            while(holder!=0)
            {
                possibleDigits.pb(holder%10);
                holder /= 10;
            }
            for(int j=0; j < possibleDigits.size() ;j++)
            {
                minDigits[value] = min(minDigits[value], minDigits[value-possibleDigits[j]]+1);
            }
        }
        cout << minDigits[n] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}