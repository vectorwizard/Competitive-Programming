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
    string a,c;
    cin>>a>>c;
    string b = "";
    for(ll i=0;i<n;i++){
        if(a[i]==c[i]) b+='0';
        else b+='1';
    }
    ll m = (1<<k) + 1;
    ll ans1 = 0,ans2=0,ans3=0;
    ll cnta1=0,cnta0=0;
    ll cntb1=0,cntb0=0;
    ll cntc1=0,cntc0=0;
    for(ll i=0;i<n;i++){   
        if(a[i]=='0') cnta0++;
        else cnta1++;
        if(b[i]=='0') cntb0++;
        else cntb1++;
        if(c[i]=='0') cntc0++;
        else cntc1++;
    }
    ans1 = (cnta1*cnta0);
    ans2 = (cntb1*cntb0);
    ans3 = (cntc1*cntc0);
    if(k%2==1){
        ll x = (1<<k)+1;
        ll y = x/3;
        cout<<(ans1*y+ans2*y+ans3*y)<<endl;
        return;
    }
    else{
        ll x = (1<<k)+1;
        ll y = x/3;
        cout<<(y*ans2+(y+1)*ans3+(y+1)*ans1)<<endl;
        return;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
