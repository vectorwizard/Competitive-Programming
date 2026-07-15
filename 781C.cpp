#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> &a){
    ll n = a.size();
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        ll rem = max(0LL,a[i]-mid);
        cnt+=rem;
    }
    if(cnt<=mid) return true;
    return false;
}

void solve() {  
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=2;i<=n;i++){
        ll p;
        cin>>p;
        adj[p].push_back(i);
    }
    vector<ll> vec;
    for(ll i=1;i<=n;i++){
        if(adj[i].size()>0) vec.push_back(adj[i].size());
    }
    vec.push_back(1);
    sort(vec.rbegin(),vec.rend());
    vector<ll> a;
    ll k = vec.size();
    ll cnt = k;
    for(ll i=0;i<k;i++){
        ll rem = vec[i] - 1 - (k-i-1);
        if(rem>0){
            a.push_back(rem);
        }
    }
    ll low = 0;
    ll high = 1e9;
    ll ans = 1e9;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<(cnt+ans)<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
