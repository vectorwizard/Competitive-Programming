#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m,x;
    cin>>n>>m>>x;
    vector<ll> a(n);
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++){
        vec[i] = {a[i],i};
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    sort(vec.begin(),vec.end());
    vector<ll> ans(n);
    for(ll i=0;i<m;i++){
        pq.push({vec[i].first,i+1});
        ans[vec[i].second] = i+1;
    }
    for(ll i=m;i<n;i++){
        auto it = pq.top();
        pq.pop();
        ll x = it.first;
        ll y = it.second;
        pq.push({x+vec[i].first,y});
        ans[vec[i].second] = y;
    }
    ll maxi = 0;
    ll mini = 1e18;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll first = it.first;
        maxi = max(maxi,first);
        mini = min(mini,first);
    }
    if((maxi-mini)>x){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}