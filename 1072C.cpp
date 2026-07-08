#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
unordered_map<int,int> dp;

int func(int n,int k){
    if(n==k) return 0;
    else if(n<k) return 1e9;
    if(dp.count(n)){
        return dp[n];
    }
    int ans =0;
    if(n%2==0){
        int x = (func(n/2,k));
        if(x<1e9) ans = 1+x;
        else ans = 1e9;
    }
    else{
        int x = 1e9,y=1e9;
        x = 1+func(n/2,k);
        y = 1+func((n+1)/2,k);
        int w = min(x,y);
        ans =w;
    }
    return dp[n]=ans;
}
void solve() {
    int n,k;
    cin>>n>>k;
    dp.clear();
    int ans = func(n,k);
    if(ans>=1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
