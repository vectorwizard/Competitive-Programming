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
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> gaps;
    for(int i=1;i<m;i++){
        gaps.push_back(a[i]-a[i-1]-1);
    }
    gaps.push_back((n-a[m-1])+(a[0]-1));
    sort(gaps.rbegin(),gaps.rend());
    int day = 0;
    int saved = 0;
    for(auto it:gaps){
        int gap = it - day*2;
        if(gap==1){
            day++;
            saved++;
        }
        else if(gap>0){
            saved+=(gap-1);
        }
        day+=2;
    }
    cout<<(n-saved)<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
