#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll comm(ll s,ll t){
    for(ll i=0;i<=32;i++){
        ll st1 = (s&(1LL<<i));
        ll st2 = (t&(1LL<<i));
        if(st1==0 && st2==0) return i;
    }
    return 33;
}

ll low(ll n){
    for(int i=0;i<=32;i++){
        if((n&(1LL<<i))==0) return i;
    }
    return 32;
}

void solve() {
    ll n,q;
    cin>>n>>q;
    while(q--){
        ll s,t;
        cin>>s>>t;
        if(s==t){
            cout<<0<<endl;
            continue;
        }
        if((s&t)==0){
            cout<<s+t<<endl;
            continue;
        }
        ll mini = 1e18;
        ll x = comm(s,t); 
        if((1LL<<x)<=n) mini = s+t+2*(1LL<<x);
        x = low(s);
        ll y = low(t);
        if(((1LL<<x)<=n)&&(1LL<<y)<=n) mini = min(mini,s+t+2*((1LL<<x)+(1LL<<y)));
        if(mini==1e18) cout<<-1LL<<endl;
        else cout<<mini<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}