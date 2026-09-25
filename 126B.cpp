#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        int best = 15; 
        for (int add = 0; add <= 15; add++) {
            int curr = (x + add) % 32768;
            int mult = 0;
            
            while (curr != 0) {
                curr = (curr * 2) % 32768;
                mult++;
            }
            
            best = min(best, add + mult);
        }
        
        cout << best << " ";
    }
    
    cout << "\n";
    return 0;
}