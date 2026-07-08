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
    ll sum = accumulate(a.begin(),a.end(),0LL);
    ll last = 0;
    ll time = 1;
    vector<ll> timestamp(n,0);
    ll lasttime = -1;
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll i,x;
            cin>>i>>x;
            i--;
            if(timestamp[i]<lasttime){
                a[i] = x;
                sum-=last;
                sum+=a[i];
            }
            else{
                sum-=a[i];
                sum+=x;
                a[i] = x;
            }
            timestamp[i] = time;
            cout<<sum<<endl;
        }
        else{
            ll x;
            cin>>x;
            last = x;
            lasttime = time;
            sum = n*x;
            cout<<sum<<endl;
        }
        time++;
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
