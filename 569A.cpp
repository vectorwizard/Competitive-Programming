#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    if(q==0) return;
    vector<pair<ll,ll>> vec(q);
    for(ll i=0;i<q;i++){
        ll x;
        cin>>x;
        vec[i] = {x,i};
    } 
    sort(vec.begin(),vec.end());
    vector<pair<ll,ll>> ans(q);
    ll ind = 0;
    ll maxi = *max_element(a.begin(),a.end());
    deque<ll> dq;
    for(ll i=0;i<n;i++) dq.push_back(a[i]);
    ll cnt = 0;
    while(ind<q && dq.front()!=maxi){
        cnt++;
        ll first = dq.front();
        dq.pop_front();
        ll second = dq.front();
        dq.pop_front();
        if(first>second){
            dq.push_front(first);
            dq.push_back(second);
        }
        else{
            dq.push_front(second);
            dq.push_back(first);
        }
        while(ind<q && cnt==vec[ind].first){
            ans[vec[ind].second] = {first,second};
            ind++;
        }
    }
    vector<ll> final;
    dq.pop_front();
    while(!dq.empty()){
        ll x = dq.front();
        dq.pop_front();
        final.push_back(x);
    }
    while(ind<q){
        ll flips = vec[ind].first;
        flips-=cnt;
        flips=(flips-1)%(n-1);
        ans[vec[ind].second] = {maxi,final[flips]};
        ind++;
    }
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
