#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int x;
    cin>>x;
    int cnt = 0;
    vector<int> ans;
    while(__builtin_popcount(x)!=(32 - __builtin_clz(x))){
        if(cnt%2==0){
            int bit;
            for(int i=31-__builtin_clz(x);i>=0;i--){
                if((x&(1<<i))==0){
                    bit = i;
                    break;
                }
            }
            x = x ^ ((1<<(bit+1))-1);
            ans.push_back(bit+1);
        }
        else x = x+1;
        cnt++;
    }
    cout<<cnt<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}