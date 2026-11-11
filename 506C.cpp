#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    ll maxi = 0;
    ll mini = 1e12;
    map<ll,vector<ll>> mpp;
    for(ll i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        a[i] = {l,r};
        maxi = max(maxi,l);
        mini = min(mini,r);
    }
    sort(a.begin(),a.end());
    for(ll i=n-1;i>=0;i--){
        mpp[a[i].first].push_back(a[i].second);
    }
    ll ans = 0;
    pair<ll,ll> target = {maxi,mpp[maxi][0]};
    vector<pair<ll,ll>> temp;
    bool taken = false;
    for(ll i=0;i<n;i++){
        if(a[i]==target && taken==false){
            taken = true;
        }
        else temp.push_back(a[i]);
    }
    ll maxim = 0;
    ll minim = 1e12;
    for(ll i=0;i<n-1;i++){
        maxim = max(maxim,temp[i].first);
        minim = min(minim,temp[i].second);
    }
    if(maxim<minim) ans = max(ans,(minim - maxim));
    mpp.clear();
    temp.clear();
    for(ll i=0;i<n;i++){
        mpp[a[i].second].push_back(a[i].first);
    }
    target = {mpp[mini][0],mini};
    taken = false;
    for(ll i=0;i<n;i++){
        if(a[i]==target && taken==false){
            taken = true;
        }
        else temp.push_back(a[i]);
    }
    maxim = 0;
    minim = 1e12;
    for(ll i=0;i<n-1;i++){
        maxim = max(maxim,temp[i].first);
        minim = min(minim,temp[i].second);
    }
    if(maxim<minim) ans = max(ans,(minim - maxim));
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}