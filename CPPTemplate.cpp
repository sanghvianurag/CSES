#include<iostream>
#include<vector>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i=a;i<b;++i)
#define repb(i, a, b) for(int i=a;i>b;--i)
#define endl '\n'
#define mod 1000000007

long long binpow(long long a, long long b)
{
    if(b == 0) return 1;
    long long res = binpow(a, b/2);
    if(b & 1)
        return (((res%mod)*(res%mod)*(a%mod))%mod);
    else
        return ((res%mod)*(res%mod)%mod);
}


void solve(){
  ll N;
  cin >> N;
  cout << binpow(2, N);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}