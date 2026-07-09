#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,w;
    cin>>n>>w;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        vec[i] = {a[i],i+1};
    }
    sort(vec.begin(),vec.end());
    ll target = (w+1)/2;
    ll i = n-1;
    while(i>=0 && vec[i].first>=target){
        if(vec[i].first>=target && vec[i].first<=w){
            cout<<1<<endl;
            cout<<vec[i].second<<endl;
            return;
        }
        i--;
    }   
    ll sum = 0;
    for(ll j=0;j<=i;j++){
        sum+=vec[j].first;
        if(sum>=target){
            cout<<(j+1)<<endl;
            for(ll k = 0;k<=j;k++){
                cout<<vec[k].second<<" ";
            }
            cout<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
