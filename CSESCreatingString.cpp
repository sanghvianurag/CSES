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

unordered_map<string, int> umap;
int counter = 0;

void output(){

    cout << counter << endl;
    vector<string> answer;
    for(auto x:umap)
    {
        answer.pb(x.first);
    }
    sort(answer.begin(), answer.end());
    for(auto x: answer)
    {
        cout << x << endl;
    }
}

void generatePermutations(string s, vector<int>& chosen, string perm){
    if(perm.size() == s.size())
    {
        if(umap.find(perm) == umap.end()){
            umap[perm]++;
            counter++;
            //cout << perm << endl;
            return;
        }
        else
        {
            return;
        }
    }
    rep(i, 0, s.size()){
        if(chosen[i]) continue;
        chosen[i] = 1;
        perm.pb(s[i]);
        generatePermutations(s, chosen, perm);
        chosen[i] = false;
        perm.pob();
    }
}

//function to generate all the permutations
void solve(){
    string s;
    cin >> s;
    vector<int> isPresent(8, 0);
    generatePermutations(s, isPresent, "");
    output();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}