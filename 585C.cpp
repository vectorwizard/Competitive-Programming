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
    string s,t;
    cin>>s>>t;
    ll ab = 0;
    ll ba = 0;
    vector<ll> vecab;
    vector<ll> vecba;
    for(ll i=0;i<n;i++){
        if(s[i]!=t[i]){
            if(s[i]=='a') {
                ab++;
                vecab.push_back(i);
            }
            else{
                ba++;
                vecba.push_back(i);
            }
        }
    }
    if((ab+ba)%2==1){
        cout<<-1<<endl;
        return;
    }
    if(ab%2==0){
        cout<<(ab+ba)/2<<endl;
        for(ll i=0;i<vecab.size()-1;i+=2){
            cout<<vecab[i]+1<<" "<<vecab[i+1]+1<<endl;
        }
        for(ll i=0;i<vecba.size()-1;i+=2){
            cout<<vecba[i]+1<<" "<<vecba[i+1]+1<<endl;
        }
        return;
    }
    else{
        ll ans = ab/2;
        ans+=(ba/2);
        ans+=2;
        cout<<ans<<endl;
        for(ll i=0;i<vecab.size()-1;i+=2){
            cout<<vecab[i]+1<<" "<<vecab[i+1]+1<<endl;
        }
        for(ll i=0;i<vecba.size()-1;i+=2){
            cout<<vecba[i]+1<<" "<<vecba[i+1]+1<<endl;
        }
        ll m = vecab.size();
        ll n = vecba.size();
        cout<<vecab[m-1]+1<<" "<<vecab[m-1]+1<<endl;
        cout<<vecab[m-1]+1<<" "<<vecba[n-1]+1<<endl;
    }
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
