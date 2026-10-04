
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,int> mpp;
    for(int i=0;i<n;i++) mpp[a[i]]++;
    int cnt = 0;
    for(auto it:mpp){
        if(it.second==1) continue;
        else{
            cnt+=(it.second-1);
        }
    }
    int ans = (n-cnt);
    if(cnt%2==1) ans--;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}