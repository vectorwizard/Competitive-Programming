#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
set<int> st;
void func(int ind,int sum,vector<int> &a,vector<vector<bool>> &dp){
    int n = a.size();
    if(ind==n){
        st.insert(sum);
        return;
    }
    if(dp[ind][sum]) return;
    dp[ind][sum] = true;
    func(ind+1,sum+a[ind],a,dp);
    func(ind+1,sum,a,dp);
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<bool>> dp(n+1,vector<bool> (100001,false));
    func(0,0,a,dp);
    cout<<st.size()-1<<endl;
    for(auto it:st){
        if(it==0) continue;
        cout<<it<<" ";
    }
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
