#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

bool solve(vector<int>& nums, int start, int current_sum, vector<int>& path)
{
    if(current_sum < 0)
	{
		return false;
	}
	if(current_sum == 0)
	{
        ans.push_back(path);
		return true;
	}
	if(start >= nums.size())
	{
		return false;
	}
    if(ans.size() == 0)
    {
        path.push_back(nums[start]);
        bool ans_one = solve(nums, start+1, current_sum-nums[start], path);
        path.pop_back();
        bool ans_two = solve(nums, start+1, current_sum, path);
        return (ans_one || ans_two);
    }
	return false;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    long long sum = (n*(n+1))/2;
    if(sum%2!=0)
    {
        cout << "NO" << "\n";
    }
    else
    {
        vector<int> nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        vector<int> path;
        solve(nums, 0, sum/2, path);
        vector<bool> exists(n+1, false);
        cout << ans[0].size() << "\n";
        for(int i=0;i<ans[0].size();i++)
        {
            cout << ans[0][i] << " ";
            exists[ans[0][i]] = true;
        }
        cout << "\n";
        cout << n - ans[0].size() << "\n";
        for(int i=1;i<=n;i++)
        {
            if(!exists[i])
            {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}