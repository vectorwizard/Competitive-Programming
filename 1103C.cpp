#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll a,b,x;
    cin>>a>>b>>x;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    ll ans = abs(a-b);
    vector<ll> vec1;
    vector<ll> vec2;
    vec1.push_back(a);
    vec2.push_back(b);
    while(a!=0){
        a/=x;
        vec1.push_back(a);
    }
    while(b!=0){
        b/=x;
        vec2.push_back(b);
    }
    vec1.push_back(0);
    vec2.push_back(0);
    for(ll i=0;i<vec1.size();i++){
        for(ll j=0;j<vec2.size();j++){
            ans = min(ans,(i+j+abs(vec1[i]-vec2[j])));
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
