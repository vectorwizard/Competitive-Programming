#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k,b,s;
    cin>>n>>k>>b>>s;
    if(s==(b*k)){
        cout<<s<<" ";
        for(ll i=0;i<n-1;i++){
            cout<<0<<" ";
        }
        cout<<endl;
        return;
    }
    else if((b*k)>s){
        cout<<-1<<endl;
        return;
    }
    else{
        vector<ll> ans(n);
        ans[0] = min(k*b+(k-1),s);
        s-=ans[0];
        for(ll i=1;i<n;i++){
            ans[i] = min(s,k-1);
            s-=ans[i];
        }
        if(s>0){
            cout<<-1<<endl;
            return;
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
