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
    string a,b;
    cin>>a>>b;
    ll x = 0;
    ll y = 0;
    bool fl = true;
    for(ll i=0;i<n;i++){
        if(a[i]==b[i]){
            if(a[i]=='('){
                x++;
                y++;
            }
            else {
                x--;
                y--;
            }
        }
        else{
            if(x>y){
                x--;
                y++;
            }
            else{
                x++;
                y--;
            }
        }
        if(x<0 || y<0){
            fl = false;
            break;
        }
    }
    if(x!=0 || y!=0) fl = false;
    if(fl) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
