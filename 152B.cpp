#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
static bool comp(pair<ll,ll> &a,pair<ll,ll> &b){
    if(a.first==0 && b.first==0) return a.second<b.second;
    else if(a.first==0) return true;
    else if(b.first==0) return false;
    else if(a.first!=b.first){
        return a.first>b.first;
    }
    else return a.second<b.second;
}
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<pair<ll,ll>> vec;
    for(ll i=0;i<n;i++){
        vec.push_back({a[i]%k,i+1});
    }
    sort(vec.begin(),vec.end(),comp);
    for(ll i=0;i<n;i++){
        cout<<vec[i].second<<" ";
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
