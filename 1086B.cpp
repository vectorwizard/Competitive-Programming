#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k,p,m;
    cin>>n>>k>>p>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int x = a[p];
    priority_queue<int,vector<int>,greater<int>> pq1;
    for(int i=1;i<=p-1;i++){
        pq1.push(a[i]);
    }
    int total1 = 0;
    for(int i=0;i<max(0,(p-k));i++){
        total1+=pq1.top();
        pq1.pop();
    }
    int ans = 0;
    if((total1+x)<=m)  {
        ans++;
        m-=(total1+x);
    }
    else {
        cout<<0<<endl;
        return;
    }
    priority_queue<int,vector<int>,greater<int>> pq2;
    int total2 = 0;
    for(int i=1;i<=n;i++){
        if(i==p) continue;
        pq2.push(a[i]);
    }
    for(int i=0;i<(n-k);i++){
        total2+=pq2.top();
        pq2.pop();
    }
    ans+=(m/(total2+x));
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}