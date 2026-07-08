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
    cout<<1<<" "<<1<<" "<<n<<endl;
    int x,y;
    cin>>x;
    cout<<2<<" "<<1<<" "<<n<<endl;
    cin>>y;
    int diff = y-x;
    int low = 1;
    int high = n;
    int ansl = 1;
    int ansr = n;
    while(low<=high){
        int res1,res2;
        int mid = low+(high-low)/2;
        cout<<1<<" "<<mid<<" "<<n<<endl;
        cin>>res1;
        cout<<2<<" "<<mid<<" "<<n<<endl;
        cin>>res2;
        if((res2-res1)==diff){
            ansl = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }   
    }
    ansr = ansl + diff-1;
    cout<<"!"<<" "<<ansl<<" "<<ansr<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
