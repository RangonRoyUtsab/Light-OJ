// I'm always wrong
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

// clang-format off
#define ed      '\n'
#define all(x)  x.begin(), x.end() 
#define FAST    ios_base::sync_with_stdio(0); cin.tie(0);                       
#define FRE     freopen("in.txt", "r", stdin); freopen("in.txt", "w", stdout);  
#define TEST    ll test; cin >> test; for (ll tt=1; tt<=test; tt++)             
#define YES(f)  cout << (f?"YES":"NO") << ed;
// clang-format on

const int IMAX = 200005;
const long long INF = 1e18;

int binary_search1(int a[], int n, int x, int y) {
  int l = -1, r = n, m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (a[m] < x) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}
int binary_search2(int a[], int n, int x, int y) {
  int l = -1, r = n, m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (y < a[m]) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}

int main() {
  FAST;
  TEST {
    int n, q;
    cin >> n >> q;
    int p[n];
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    cout << "Case " << tt << ": \n";
    for (int i = 0; i < q; i++) {
      int a, b;
      cin >> a >> b;
      int l = -1, r = n;
      l = binary_search1(p, n, a, b);
      r = binary_search2(p, n, a, b);
      if (l == -1) l = 0;
      if (r == -1) r = 0;
      while (p[l] < a) l++;
      while (p[r] > b) r--;
      cout << r - l + 1 << ed;
    }
  }
  return 0;
}

/*
LOJ 1088

Given n points (1 dimensional) and q segments, you have to find the number
of points that lie in each of the segments. A point pi will lie in a segment A B
if A ≤ pi ≤ B.

For example if the points are 1, 4, 6, 8, 10. And the segment is 0 to 5. Then
there are 2 points that lie in the segment.

Input
Input starts with an integer T (≤ 5), denoting the number of test cases.

Each case starts with a line containing two integers n (1 ≤ n ≤ 105) and q (1 ≤
q ≤ 50000). The next line contains n space separated integers denoting the
points in ascending order. All the integers are distinct and each of them range
in [0, 108].

Each of the next q lines contains two integers Ak Bk (0 ≤ Ak ≤ Bk ≤ 108)
denoting a segment.

Output
For each case, print the case number in a single line. Then for each segment,
print the number of points that lie in that segment.

Sample
Input
1
5 3
1 4 6 8 10
0 5
6 10
7 100000

Output
Case 1:
2
3
2

*/