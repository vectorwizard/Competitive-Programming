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
    map<int,int> mpp;
    for(int i=0;i<n;i++) mpp[a[i]]++;
    int ans = 0;
    int prev = -1;
    int prev_freq = 0;
    int cons_freq = 0;
    for(auto it:mpp){
        int x = it.first;
        int freq = it.second;
        if(x-prev==1){
            if((freq-prev_freq)>0){
                cons_freq += (freq-prev_freq);
            }
            else if((freq-prev_freq)<0){
                cons_freq-=(prev_freq-freq);
                ans+=(prev_freq-freq);
            }
            prev_freq = freq;
            prev = x;
        }
        else{
            ans+=cons_freq;
            cons_freq = freq;
            prev_freq = freq;
            prev = x;
        }
    }
    ans+=cons_freq;
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
