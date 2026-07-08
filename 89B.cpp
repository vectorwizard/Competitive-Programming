#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x,m;
    cin>>n>>x>>m;
    ll l_ptr = x;
    ll r_ptr = x;
    ll cnt = 1;
    while(m--){
        ll l,r;
        cin>>l>>r;
        if(r<l_ptr || l>r_ptr){
            continue;
        }
        else if(r<=r_ptr && l>=l_ptr){
            continue;
        }
        else if(r>=r_ptr && l<=l_ptr){
            cnt+=(r-r_ptr);
            cnt+=(l_ptr-l);
            r_ptr = r;
            l_ptr = l;
        }
        else if(r>r_ptr){
            cnt+=(r-r_ptr);
            r_ptr = r;
        }
        else if(l<l_ptr){
            cnt+=(l_ptr-l);
            l_ptr = l;
        }
    }
    cout<<cnt<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
