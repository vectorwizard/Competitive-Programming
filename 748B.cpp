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
    string s = to_string(n);
    ll siz = s.size();
    ll mini = siz;
    ll zero = siz;
    for(ll i=siz-1;i>=0;i--){
        if(s[i]=='0'){
            zero = i;
            break;
        }
    }
    if(zero!=siz){
        ll five = siz;
        for(ll i=zero-1;i>=0;i--){
            if(s[i]=='0' || s[i]=='5'){
                five = i;
                break;
            }
        }
        if(five!=siz){
            ll x = (siz-zero-1)+(zero-five-1);
            mini = min(mini,x);
        }
    }
    ll five = siz;
    for(ll i=siz-1;i>=0;i--){
        if(s[i]=='5'){
            five = i;
            break;
        }
    }
    if(five!=siz){
        ll two = siz;
        for(ll i=five-1;i>=0;i--){
            if(s[i]=='2' || s[i]=='7'){
                two = i;
                break;
            }
        }
        if(two!=siz){
            ll x = (siz-five-1)+(five-two-1);
            mini = min(mini,x);
        }
    }
    cout<<mini<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
