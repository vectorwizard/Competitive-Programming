#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(vector<ll> &a,ll mid){
    ll n = a.size();
    set<ll> st;
    for(ll i=0;i<mid;i++) st.insert(i);
    vector<ll> extras;
    for(ll i=0;i<n;i++){
        if(st.count(a[i])>0){
            st.erase(a[i]);
        }
        else{
            extras.push_back(a[i]);
        }
    }
    vector<ll> need;
    for(auto it:st){
        need.push_back(it);
    }
    ll y = 0;
    for(ll i=0;i<need.size();i++){
        ll x = need[i]*2 + 1;
        ll ind = lower_bound(extras.begin()+y,extras.end(),x) - extras.begin();
        if(ind==extras.size()) return false;
        y = ind+1;
    }
    return true;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll low = 0;
    ll high = n;
    ll ans = 0;
    sort(a.begin(),a.end());
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(a,mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
