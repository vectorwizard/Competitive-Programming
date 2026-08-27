#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') cnt++;
        else cnt--;
    }
    if(cnt!=0){
        cout<<-1<<endl;
        return;
    }
    cnt = 0;
    int ans = 0;
    bool fl = true;
    int x = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') cnt++;
        else cnt--;
        if(cnt<0){
            if(fl == true){
                x = 1;
                fl = false;
            }
            else{
                x++;
                continue;
            }
        }
        else if(cnt==0){
            if(fl==false){
                ans+=(x+1);
                x = 0;
                fl = true;
            }
        }
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
