#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll mid,vector<ll> &a,ll l,vector<vector<ll>> &hash){
    ll n = a.size();
    ll len = mid-l;
    vector<ll> vec(31,0);
    for(ll i=0;i<31;i++){
        if((a[l] & (1<<i))==0) vec[i] = 0;
        else{
            ll cnt = hash[i][mid] - hash[i][l];
            if(cnt!=len) vec[i] = 0;
            else vec[i] = 1;
        } 
    }
    ll ans = 0;
    ll x = 1;
    for(ll i=0;i<31;i++){
        if(vec[i]==1) ans += x;;
        x = x*2;
    }
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll q;
    cin>>q;
    vector<vector<ll>> hash(31,vector<ll>(n,0));
    for(ll i=0;i<31;i++){
        for(ll j=0;j<n;j++){
            ll x=0;
            if(j>0) x = hash[i][j-1];
            if((a[j]&(1<<i))!=0) hash[i][j] = x+1;
            else hash[i][j] = x;
        }
    }
    while(q--){
        ll l,k;
        cin>>l>>k;
        l--;
        if(a[l]<k){
            cout<<-1<<" ";
            continue;
        }
        ll high = n-1;
        ll low = l;
        ll ans = l;
        while(low<=high){
            ll mid = low+(high-low)/2;
            ll x = func(mid,a,l,hash);
            if(x>=k){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        cout<<(ans+1)<<" ";
    }
    cout<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
