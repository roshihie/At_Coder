#include <bits/stdc++.h>
using namespace std;

// dp[i][j][k][m] :=  i: 上位 i 桁目まで決定
//                    j: small(数字を自由に選べる)か
//                    k: started(数字を書き込んだ)か
//                    m: {3,5,7} を選んだかのflag
//                    としたときの753数の数
int dp[11][2][2][8];

int main()
{
  cin.tie(0); ios::sync_with_stdio(false);

  string n;
  cin >> n;

  int len = n.size();
  dp[0][0][0][0] = 1;
  for (int i = 0; i < len; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      for (int k = 0; k < 2; ++k)
      {
        for (int m = 0; m < 8; ++m)
        {
          if (!dp[i][j][k][m]) continue;

          if (j == 1)                  // small ([0, 9] から数字を選べる)か
          {
            if (k == 0 && m == 0)      // not started (数字を書き込んでいない)か
              dp[i + 1][1][0][0] += dp[i][1][0][0];                // nothing

            dp[i + 1][1][1][m | 1] += dp[i][1][k][m];              // +3
            dp[i + 1][1][1][m | 2] += dp[i][1][k][m];              // +5
            dp[i + 1][1][1][m | 4] += dp[i][1][k][m];              // +7
          }
          else                         // not small ([0, d] から数字を選べる)か
          {
            int d = n[i] - '0';

            if (k == 0 && m == 0)      // not started (数字を書き込んでいない)か
              dp[i + 1][1][0][0] += dp[i][0][0][0];                // nothing

            if (d == 3) dp[i + 1][0][1][m | 1] += dp[i][0][k][m];  // +3
            if (3 < d)  dp[i + 1][1][1][m | 1] += dp[i][0][k][m];  // +3
            if (d == 5) dp[i + 1][0][1][m | 2] += dp[i][0][k][m];  // +5
            if (5 < d)  dp[i + 1][1][1][m | 2] += dp[i][0][k][m];  // +5
            if (d == 7) dp[i + 1][0][1][m | 4] += dp[i][0][k][m];  // +7
            if (7 < d)  dp[i + 1][1][1][m | 4] += dp[i][0][k][m];  // +7
          }
        }
      }
    }
  }

  int ans = dp[len][0][1][7] + dp[len][1][1][7];
  cout << ans << endl;
//  Debug Coding 
  for (int i = 0; i <= len; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        for (int m = 0; m < 8; ++m)
          if (dp[i][j][k][m])
          {
            cout << "dp[" << i << "][" << j << "][" << k << "][" << m << "] = (";
            cout << dp[i][j][k][m] << ")" << endl;
          }

  return 0;
}
