#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> mods;
    for(int i=0;i<n;i++){
        mods.push_back(a[i]%m);
    }
    map<int,int> mpp;
    for(auto it:mods){
        mpp[it]++;
    }
    int ans = 0;
    for(auto it=mpp.rbegin();it!=mpp.rend();it++){
        int val_r = it->first;
        int freq_r = it->second;
        int val_l = (m-val_r);
        int freq_l = 0;
        if(mpp.find(val_l)!=mpp.end()) freq_l = mpp[val_l];
        if(freq_r==0 || freq_l==0) continue;
        if(freq_r<freq_l){
            mpp[val_r]=0;
            mpp[val_l]-=(freq_r+1);
            ans++;
        }
        else if(freq_r>freq_l){
            mpp[val_l]=0;
            mpp[val_r]-=(freq_l+1);
            ans++;
        }
        else{
            mpp[val_l]=0;
            mpp[val_r]=0;
            ans++;
        }
    }
    if(mpp.find(0)!=mpp.end() && mpp[0]>0){
        ans++;
        mpp[0]=0;
    }
    for(auto it:mpp){
        ans+=it.second;
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

