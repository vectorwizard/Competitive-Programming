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
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    if(mpp.size()>2) cout<<"NO"<<endl;
    else if(mpp.size()==1) cout<<"YES"<<endl;
    else {
        if(n%2==1){
            vector<int> vec;
            for(auto it:mpp){
                vec.push_back(it.second);
            }
            if(abs(vec[0]-vec[1])==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            vector<int> vec;
            for(auto it:mpp){
                vec.push_back(it.second);
            }
            if(abs(vec[0]==vec[1])) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
