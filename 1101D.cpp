#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x,s;
    cin>>n>>x>>s;
    string st;
    cin>>st;
    ll ans = 0;
    ll tables = 0;
    ll seats = 0;
    ll bad = 0;
    for(ll i=0;i<n;i++){
        if(st[i]=='I'){
            if(tables<x){
                ans++;
                tables++;
                seats+=(s-1);
            }
        }
        else if(st[i]=='A'){
            if(seats>0){
                bad++;
                ans++;
                seats--;
            }
            else{
                if(tables<x){
                    ans++;
                    tables++;
                    seats+=(s-1);
                }
            }
        }
        else{
            if(seats>0){
                seats--;
                ans++;
            }
            else{
                if(bad>0 && tables<x){
                    bad--;
                    seats++;
                    tables++;
                    seats+=(s-1);
                    seats--;
                    ans++;
                }
            }
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