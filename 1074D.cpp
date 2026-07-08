#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m,h;
    cin>>n>>m>>h;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<pair<int,int>> ops(m);
    for(int i=0;i<m;i++){
        int b,c;
        cin>>b>>c;
        b--;
        ops[i] = {b,c};
    }
    vector<int> change(n,0);
    vector<int> change_ind;
    for(int i=0;i<m;i++){
        auto it = ops[i];
        int b = it.first;
        int c = it.second;
        if(a[b]+c<=h){
            a[b] = a[b]+c;
            if(change[b]==0) change_ind.push_back(b);
            change[b]+=c;
        }
        else{
            int size = change_ind.size();
            for(int k=0;k<size;k++){
                int ind = change_ind[k];
                a[ind]=a[ind]-change[ind];
                change[ind]=0;
            }
            change_ind.clear();
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}