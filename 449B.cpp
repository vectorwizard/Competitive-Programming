#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll mod,total;
ll ans;
void func(ll ind,ll digits,string temp){
    if(total==0) return;
    if(ind==digits){
        string rev = temp;
        reverse(rev.begin(),rev.end());
        temp = temp + rev;
        ll x = stoll(temp);
        ans = (ans + x)%mod;
        total--;
        return;
    }
    if(ind==0){
        for(char ch = '1';ch<='9';ch++){
            func(ind+1,digits,temp+ch);
        }
    }
    else{   
        for(char ch = '0';ch<='9';ch++){
            func(ind+1,digits,temp+ch);
        }
    }
}

void solve() {
    ans = 0;
    ll k,p;
    cin>>k>>p;
    mod = p;
    total = k;
    for(ll i=1;i<=6;i+=1){
        if(total==0) break;
        string temp = "";
        func(0,i,temp);
    }
    cout<<ans%mod<<endl;;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}