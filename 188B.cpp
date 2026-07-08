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
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        pq.push({a[i],i});
    }
    int maxi = n;
    int ans = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int idx = it.second;
        if(idx>=maxi) continue;
        ans++;
        maxi = min(maxi,idx);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}