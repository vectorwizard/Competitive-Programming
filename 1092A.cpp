#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(k+1);
    vector<int> b(n+1);
    for(int i=1;i<=k;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    map<int,vector<int>> mpp;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(b[i]==k+1) continue;
        mpp[b[i]].push_back(i);
    }
    for(auto it:mpp){
        int siz = it.second.size();
        ans+=(k+1-it.first)*siz;
    }
    if(ans==0){
        cout<<0<<endl;
        return;
    }
    cout<<ans<<endl;
    while(mpp.size()>0){
        auto it = mpp.rbegin();
        int level = it->first;
        int x = (k+1-level);
        for(auto it1: it->second){
            for(int i=0;i<x;i++){
                cout<<it1<<" ";
            }
        }
        mpp.erase(it->first);
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
