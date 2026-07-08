#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 676767677;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    ll ans = 1;
    vector<int> sorted = b;
    sort(sorted.begin(),sorted.end());
    unordered_map<int,int> mpp;
    mpp[sorted[0]]=1;
    for(int i=1;i<n;i++){
        if(sorted[i]==sorted[i-1]) mpp[sorted[i]]++;
        else mpp[sorted[i]]+=mpp[sorted[i-1]]+1;
    }
    for(int i=0;i<n;i++){
        if(b[i]==0) continue;
        int left = (i > 0) ? b[i-1] : m + 1;
        int right = (i < n - 1) ? b[i+1] : m + 1;
        int min_neighbor = min(left, right);
        if(min_neighbor>=b[i]){
            cout<<0<<endl;
            return;
        }
        if(min_neighbor==b[i]-1){
            ans = (ans*mpp[b[i]-1])%mod;
        }
        else{
            ans = (ans*(mpp[b[i]-1]-mpp[b[i]-2]))%mod;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}