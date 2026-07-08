#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> a;
vector<int> b;
vector<int> c;
void solve() {
    int n;
    cin>>n;
    a.assign(n,0);
    b.assign(n,0);
    c.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++) vec.push_back({a[i],i});
    for(int i=0;i<n;i++) vec.push_back({b[i],i});
    for(int i=0;i<n;i++) vec.push_back({c[i],i});
    sort(vec.begin(),vec.end());
    int n1 = 3*n-1;
    int l = 0;
    int mini = INT_MAX;
    unordered_map<int,int> mpp;
    for(int r = 0;r<=n1;r++){
        mpp[vec[r].second]++;
        while(mpp.size()==n && mpp[vec[l].second]>1 && l<r){
            mpp[vec[l].second]--;
            if(mpp[vec[l].second]==0) mpp.erase(vec[l].second);
            l++;
        }
        if(mpp.size()==n){
            mini = min(mini,(vec[r].first-vec[l].first));
        }
    }
    cout<<mini<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
