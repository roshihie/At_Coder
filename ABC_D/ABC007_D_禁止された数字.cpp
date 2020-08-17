#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(llong& rnLeft, llong& rnRigt)
{
  cin >> rnLeft >> rnRigt;
}

llong fnDgtDP(const string& cnrsNum)
{
  // dp[nPos][nSmall][nFlag] :=  nPos  : ãˆÊ nPos Œ…–Ú‚Ü‚ÅŒˆ’è
  //                             nSmall: small(”š‚ğ©—R‚É‘I‚×‚é)‚©
  //                             nFlag : ãˆÊ nPos Œ…‚Ü‚Å‚Å 4 or 9 ‚ğŠÜ‚Ş‚©
  //                             ‚ÌğŒ‚ğ–‚½‚·”’l‚Ì”
  int nSiz = cnrsNum.size();
  llong dp[nSiz + 1][2][2] = {};

  dp[0][0][0] = 1;

  for (int nPos = 0; nPos < nSiz; nPos++)
  {
    int nDgt = cnrsNum[nPos] - '0';

    for (int nSmall = 0; nSmall < 2; nSmall++)
      for (int nFlag = 0; nFlag < 2; nFlag++)
        for (int nNum = 0; nNum <= ( nSmall ? 9 : nDgt ); nNum++)
          dp[nPos + 1][nSmall || (nNum < nDgt)][nFlag || nNum == 4 || nNum == 9]
            += dp[nPos][nSmall][nFlag];
  }
  return (dp[nSiz][0][1] + dp[nSiz][1][1]);
}

int main()
{
  llong nLeft, nRigt;

  fnInput(nLeft, nRigt);
  cout << fnDgtDP( to_string(nRigt) ) - fnDgtDP( to_string(nLeft - 1) ) << endl;
  
  return 0;
}
