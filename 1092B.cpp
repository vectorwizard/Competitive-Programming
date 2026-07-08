#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll ct,ch,cu;
    cin>>ct>>ch>>cu;
    ll ans = 0;
    ll mini = min(ct,cu);
    ans += (mini*4);
    ct-=mini;
    cu-=mini;
    mini = min(ct,ch);
    ans += (mini*5);
    ct-=mini;
    ch-=mini;
    if(ct>0){
        if(ct<=mini) ans+= (ct*2);
        else ans+=(ct*2 + 1);
    } 
    ct=0;
    ll rem = (ct+ch+cu);
    ans+=(rem*3);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
