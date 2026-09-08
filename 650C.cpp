#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll start = -1;
    ll first = -1;
    ll last = -1;
    for(ll i=0;i<n;i++){
        if(s[i]=='1'){
            first = i;
            break;
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='1'){
            last = i;
            break;
        }
    }
    if(first==-1){
        cout<<((n+k)/(k+1))<<endl;
        return;
    }
    if(first==last){
        ll x = first/(k+1);
        ll y = (n-1-last)/(k+1);
        cout<<x+y<<endl;
        return;
    }
    ll ans = first/(k+1);
    ans+= (n-1-last)/(k+1);
    ll cnt = 0;
    for(ll i=first;i<=last;i++){
        if(s[i]=='0') cnt++;
        else{
            if(cnt>k){
                ans+=((cnt-k)/(k+1));
            }
            cnt = 0;
        }
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
