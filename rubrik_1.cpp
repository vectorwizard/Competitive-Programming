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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int curr_xor = 0;
    set<int> seen;
    seen.insert(0);
    int ans = 0;    
    for(int i=0;i<n;i++){
        curr_xor = curr_xor^a[i];
        if(seen.count(curr_xor)>0){
            ans++;
            seen.clear();
            seen.insert(0);
            curr_xor=0;
        }
        else{
            seen.insert(curr_xor);
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