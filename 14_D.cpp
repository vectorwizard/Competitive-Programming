#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll> left(l);
    vector<ll> right(r);
    vector<ll> leftvis(l,0);
    vector<ll> rightvis(r,0);
    for(ll i=0;i<l;i++){
        cin>>left[i];
    }
    for(ll i=0;i<r;i++){
        cin>>right[i];
    }
    ll ans = 0;
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    ll i = 0;
    ll j = 0;
    while(i<l && j<r){
        if(left[i]==right[j]){
            leftvis[i] = 1;
            rightvis[j] = 1;
            i++;
            j++;
        }
        else if(left[i]<right[j]){
            i++;
        }
        else j++;
    }
    vector<ll> temp;
    for(ll i=0;i<l;i++){
        if(leftvis[i]==0) temp.push_back(left[i]);
    }
    left = temp;
    temp.clear();
    for(ll i=0;i<r;i++){
        if(rightvis[i]==0) temp.push_back(right[i]);
    }
    right = temp;
    l = left.size();
    r = right.size();
    if(l<r){
        ll diff = (r-l)/2;
        map<ll,ll> mpp;
        for(ll i=0;i<r;i++){
            mpp[right[i]]++;
        }
        for(auto it:mpp){
            if(diff==0) break;
            ll x = it.second/2;
            ll mini = min(x,diff);
            ans+=mini;
            diff-=mini;
        }
        ans+=(2*diff);
    }
    else if(l>r){
        ll diff = (l-r)/2;
        map<ll,ll> mpp;
        for(ll i=0;i<l;i++){
            mpp[left[i]]++;
        }
        for(auto it:mpp){
            if(diff==0) break;
            ll x = it.second/2;
            ll mini = min(x,diff);
            ans+=mini;
            diff-=mini;
        }
        ans+=(2*diff);
    }
    ans+=min(l,r);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}