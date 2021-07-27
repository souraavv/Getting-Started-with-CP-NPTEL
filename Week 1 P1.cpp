#include <bits/stdc++.h>
using namespace std;

#define int long int

void go() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int left, right;
    
    auto check = [&](int mid) {
        for (int i = 1; i <= n; ++i) {
            int curVal = (i * mid) / k;
            if (curVal < a[i - 1]) {
                return -1;
            } else if (curVal > a[i - 1]) {
                return 1;
            }
        }
        return 0;
    };
    
  	auto findL = [&] () {
  	    int l = 0, r = 1e13;
  	    int lower = r;
  	    while (l <= r) {
  	        int mid = (l + r) / 2;
  	        int ret = check(mid);
  	        if (ret == 0) {
  	            lower = min(lower, mid);
  	            r = mid - 1;
  	        }
  	        else if (ret > 0) {
  	            r = mid - 1;
  	        }
  	        else {
  	            l = mid + 1;
  	        }
  	    }
  		return lower;
    };
    
    auto findR = [&] () {
  	    int l = 0, r = 1e13;
  	    int upper = l;
  	    while (l <= r) {
  	        int mid = (l + r) / 2;
  	        int ret = check(mid);
  	        if (ret == 0) {
  	            upper = max(upper, mid);
  	            l = mid + 1;
  	        }
  	        else if (ret > 0) {
  	            r = mid - 1;
  	        }
  	        else {
  	            l = mid + 1;
  	        }
  	    }
  		return upper;
    };
    
    cout << findL() << ' ' << findR() << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        go();
    }
    return 0;
}
