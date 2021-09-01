#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

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
  string s;
  cin >> s;
  int n = s.size();
  unordered_map<int,int> umap;
  bool foundOneYet = false;
  bool faulty = false;
  rep(i, 0, n){
    umap[s[i]]++;
  }
  char oddChar = '.';
  for(auto x: umap)
  {
    if(x.second%2!=0){
        if(x.second%2!=0 && !foundOneYet){
            oddChar = x.first;
            umap[x.first]--;
            foundOneYet = true;
        }
        else
        {
            faulty = true;
            cout << "NO SOLUTION" << endl;
            break;
        }
    }
  }
  if(!faulty){
      string answer = "";
      for(auto x: umap)
      {
        char ch = x.first;
        int count = x.second/2;
        while(count!=0)
        {
            answer.push_back(ch);
            count--;
        }
      }
      string backwards = answer;
      reverse(backwards.begin(), backwards.end());
      if(oddChar != '.'){
        answer.pb(oddChar);
      }
      answer += backwards;
      cout << answer << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}