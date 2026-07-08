#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }
    vector<int> valids;
    for(auto it:mpp){
        if(it.second>=k) valids.push_back(it.first);
    }
    if(valids.size()==0){
        cout<<-1<<endl;
        return;
    }
    int best_l = valids[0];
    int best_r = valids[0];
    int curr_l = valids[0];
    int maxi = 0;
    for(int i=1;i<valids.size();i++){
        if(valids[i]==valids[i-1]+1){
            if(valids[i]-curr_l>maxi){
                maxi = valids[i]-curr_l;
                best_l = curr_l;
                best_r = valids[i];
            }
        }
        else{
            curr_l = valids[i];
        }
    }
    cout<<best_l<<" "<<best_r<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
