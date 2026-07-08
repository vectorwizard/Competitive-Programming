#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<int> patches;
    int cnt = 0;
    bool front = true;
    bool back = true;
    int cntones = 0;
    for(int i=0;i<n;i++){
        if(i==0&&s[i]=='1') front = false;
        if(i==n-1&&s[i]=='1') back = false;
        if(s[i]=='0') cnt++;
        else{
            cntones++;
            patches.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt>0) patches.push_back(cnt);
    int ans = 0;
    if(cntones==0){
        if(patches[0]==1) cout<<1<<endl;
        else{
            cout<<(patches[0]+2)/3<<endl;
        }
        return;
    }
    int noofpathches = patches.size();
    for(int i=0;i<noofpathches;i++){
        if(front==true && i==0){
            ans+=((patches[i]+1)/3);
        }
        else if(back==true && i==noofpathches-1){
            ans+=((patches[i]+1)/3);
        }
        else{
            ans+=patches[i]/3;
        }
    }
    cout<<ans+cntones<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
