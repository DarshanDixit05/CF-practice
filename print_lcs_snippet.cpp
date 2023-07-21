#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int f(string a, string b, int i, int j, vector<vector<int>>&dp)
{
    if(i<0 or j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    
    int len = 0;
    if(a[i]==b[j]){
        len = max(len, 1 + f(a, b, i-1, j-1, dp));
    }else len = f(a, b, i-1, j, dp);
    
    return dp[i][j] = len;
}
void solve()
{
    string a, b;
    cin>>a;
    cin>>b;
    
    vector<vector<int>>dp(a.size()+1, vector<int>(b.size()+1, -1));
    int val = f(a, b, a.size()-1, b.size()-1, dp);
    cout<<val<<endl;
    
    string ans;
    int i=a.size()-1, j=b.size()-1;
    while(i>=0 and j>=0)
    {
        if(a[i]==b[j]){
            ans+=a[i];
            i--;
            j--;
        }else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }else if(dp[i][j-1]<dp[i-1][j]){
                i--;
            }
        }
    }  
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}

int32_t main()
{
    fast
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
