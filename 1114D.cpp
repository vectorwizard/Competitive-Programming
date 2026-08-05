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
    string a,b;
    cin>>a>>b;
    vector<ll> odda;
    vector<ll> evena;
    vector<ll> oddb;
    vector<ll> evenb;
    for(ll i=0;i<n;i++){
        if(a[i]=='1'){
            if(i%2==0) evena.push_back(i);
            else odda.push_back(i);
        }
        if(b[i]=='1'){
            if(i%2==0) evenb.push_back(i);
            else oddb.push_back(i);
        }
    }
    if((odda.size()+evena.size())!=(oddb.size()+evenb.size())){
        cout<<-1<<endl;
        return;
    }
    if((odda.size()!=oddb.size()) || (evena.size()!=evenb.size())){
        cout<<-1<<endl;
        return;
    }
    ll ans = 0;
    for(ll i=0;i<odda.size();i++){
        ans += (abs(odda[i]-oddb[i]))/2;
    }
    for(ll i=0;i<evena.size();i++){
        ans += (abs(evena[i]-evenb[i]))/2;
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
