#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<vector<ll>> &a,ll k){
    ll n = a.size();
    ll cost = 0;
    for(ll i=0;i<n;i++){
        ll x = a[i][0];
        ll y = a[i][1];
        ll z = a[i][2];
        ll sum = x+y+z;
        if(sum>=mid) continue;
        if(x>y || x>z || y>z){
            cost+=(mid-sum);
        }
        else{
            ll mini = 2e18;
            if(y>x){
                ll cnt = min((y-x+1),(z-y+1));
                z-=cnt;
                ll newsum = x+y+z;
                cnt+=max(0LL,mid-newsum);
                mini = min(mini,cnt);
            }
            else if(z>x){
                ll cnt = y-x+1;
                y-=cnt;
                ll newsum = x+y+z;
                cnt+=max(0LL,mid-newsum);
                mini = min(mini,cnt);
            }
            cost+=mini;
        }
        if(cost>k) return false;
    }
    return (cost<=k);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> a(n,vector<ll>(3));
    for(ll i=0;i<n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        a[i] = {x,y,z};
    }
    ll low = -2e18;
    ll high = 2e18;
    ll ans = low;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,k)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
