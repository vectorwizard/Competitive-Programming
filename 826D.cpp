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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll cnt = 0;
    vector<pair<ll,ll>> vec;
    for(ll i=0;i<n-1;i+=2){
        ll mini = min(a[i],a[i+1]);
        ll maxi = max(a[i],a[i+1]);
        if((maxi-mini)>1){
            cout<<-1<<endl;
            return;
        }
        if(a[i]>a[i+1]) cnt++;
        vec.push_back({mini,maxi});
    }
    while(vec.size()>1){
        ll siz = vec.size();
        vector<pair<ll,ll>> temp;
        for(ll i=0;i<siz-1;i+=2){
            ll last = vec[i].second;
            ll first = vec[i+1].first;
            if(abs(first-last)!=1 && abs(vec[i].first-vec[i+1].second)!=1){
                cout<<-1<<endl;
                return;
            }
            if(last<first){
                temp.push_back({vec[i].first,vec[i+1].second});
            }
            else{
                cnt++;
                temp.push_back({vec[i+1].first,vec[i].second});
            }
        }
        vec = temp;
    }
    cout<<cnt<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
