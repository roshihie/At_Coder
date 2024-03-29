#include <bits/stdc++.h>
using namespace std;

void input(string& rsMaxNum)
{
  cin >> rsMaxNum;
}

int digitDp(string sMaxNum)
{
  // dp[nPos][nSmall][nFlag] :=  nPos  : 上位 nPos 桁目まで決定
  //                             nSmall: small(数字を自由に選べる)か
  //                             nFlag : 上位 nPos 桁までで {3,5,7} を選択したかflag
  //                             ( 0:選択なし, 1: 3   選択, 2: 5   選択, 3: 3 5   選択, 
  //                               4: 7 選択 , 5: 3 7 選択, 6: 5 7 選択, 7: 3 5 7 選択 )
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
          if (!nFlag)
            dp[nPos + 1][1][0]       += dp[nPos][1][0];                    // nothing

          dp[nPos + 1][1][nFlag | 1] += dp[nPos][1][nFlag];                // +3
          dp[nPos + 1][1][nFlag | 2] += dp[nPos][1][nFlag];                // +5
          dp[nPos + 1][1][nFlag | 4] += dp[nPos][1][nFlag];                // +7
        }
        else                           // not small ([0, nDgt] から数字を選べる)か
        {
          int nDgt = sMaxNum[nPos] - '0';

          if (!nFlag)    dp[nPos + 1][1][0]         += dp[nPos][0][0];     // nothing

          if (nDgt == 3) dp[nPos + 1][0][nFlag | 1] += dp[nPos][0][nFlag]; // +3
          if (3 < nDgt ) dp[nPos + 1][1][nFlag | 1] += dp[nPos][0][nFlag]; // +3
          if (nDgt == 5) dp[nPos + 1][0][nFlag | 2] += dp[nPos][0][nFlag]; // +5
          if (5 < nDgt ) dp[nPos + 1][1][nFlag | 2] += dp[nPos][0][nFlag]; // +5
          if (nDgt == 7) dp[nPos + 1][0][nFlag | 4] += dp[nPos][0][nFlag]; // +7
          if (7 < nDgt ) dp[nPos + 1][1][nFlag | 4] += dp[nPos][0][nFlag]; // +7
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

  input(sMaxNum);
  cout << digitDp(sMaxNum) << endl;
  
  return 0;
}
