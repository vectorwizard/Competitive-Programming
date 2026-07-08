#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int n,m;
int lcs(int ind1,int ind2,vector<int> &a,vector<int> &b,vector<vector<int>> &dp){
    if(ind1==n || ind2==m) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(a[ind1]==b[ind2]) return dp[ind1][ind2]=1+lcs(ind1+1,ind2+1,a,b,dp);
    int ch1 = lcs(ind1+1,ind2,a,b,dp);
    int ch2 = lcs(ind1,ind2+1,a,b,dp);
    return dp[ind1][ind2]=max(ch1,ch2);
}
void solve() {
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans = lcs(0,0,a,b,dp);
    cout<<ans<<endl;
    vector<int> vec;
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            vec.push_back(a[i]);
            i++;
            j++;
        }
        else{
            if(dp[i+1][j]>dp[i][j+1]) i++;
            else j++;
        }
    }
    for(auto it:vec){
        cout<<it<<" ";
    }
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
