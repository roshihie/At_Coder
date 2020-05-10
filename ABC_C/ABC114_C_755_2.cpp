#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsMaxNum)
{
  cin >> rsMaxNum;
}

int fnDgtDP(string sMaxNum)
{
  // dp[nPos][nSmall][nFlag] :=  nPos: 上位 nPos 桁目まで決定
  //                             nSmall: small(数字を自由に選べる)か
  //                             nFlag: {3,5,7} を選んだかのflag
  //                             の条件を満たす数値の数
  int dp[11][2][8] = {};
  dp[0][0][0] = 1;

  int nLen = sMaxNum.size();

  for (int nPos = 0; nPos < nLen; ++nPos)
    for (int nSmall = 0; nSmall < 2; ++nSmall)
      for (int nFlag = 0; nFlag < 8; ++nFlag)
      {
        if (!dp[nPos][nSmall][nFlag]) continue;

        if (nSmall == 1)               // small ([0, 9] から数字を選べる)か
        {
          if (!nFlag) dp[nPos + 1][1][0] += dp[nPos][1][0];                // nothing

          dp[nPos + 1][1][nFlag | 1] += dp[nPos][1][nFlag];                // +3
          dp[nPos + 1][1][nFlag | 2] += dp[nPos][1][nFlag];                // +5
          dp[nPos + 1][1][nFlag | 4] += dp[nPos][1][nFlag];                // +7
        }
        else                           // not small ([0, d] から数字を選べる)か
        {
          int nDgt = sMaxNum[nPos] - '0';

          if (!nFlag)        dp[nPos + 1][1][0]     += dp[nPos][0][0];     // nothing

          if (nDgt == 3) dp[nPos + 1][0][nFlag | 1] += dp[nPos][0][nFlag]; // +3
          if (3 < nDgt)  dp[nPos + 1][1][nFlag | 1] += dp[nPos][0][nFlag]; // +3
          if (nDgt == 5) dp[nPos + 1][0][nFlag | 2] += dp[nPos][0][nFlag]; // +5
          if (5 < nDgt)  dp[nPos + 1][1][nFlag | 2] += dp[nPos][0][nFlag]; // +5
          if (nDgt == 7) dp[nPos + 1][0][nFlag | 4] += dp[nPos][0][nFlag]; // +7
          if (7 < nDgt)  dp[nPos + 1][1][nFlag | 4] += dp[nPos][0][nFlag]; // +7
        }
      }
/*
  for (int nPos = 0; nPos <= nLen; ++nPos)
     for (int nSmall = 0; nSmall < 2; ++nSmall)
       for (int nFlag = 0; nFlag < 8; ++nFlag)
         if (dp[nPos][nSmall][nFlag])
         {
           cout << "dp[" << nPos << "][" << nSmall << "][" << nFlag << "] = (";
           cout << dp[nPos][nSmall][nFlag] << ")" << endl;
         }
*/
  return dp[nLen][0][7] + dp[nLen][1][7];
}

int main()
{
  string sMaxNum;

  fnInput(sMaxNum);
  cout << fnDgtDP(sMaxNum) << endl;
  
  return 0;
}
