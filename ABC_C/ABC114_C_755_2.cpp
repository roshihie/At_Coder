#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsMaxNum)
{
  cin >> rsMaxNum;
}

int fnDgtDP(string sMaxNum)
{
  // dp[i][j][k] :=  i: ��� i ���ڂ܂Ō���
  //                 j: small(���������R�ɑI�ׂ�)��
  //                 k: {3,5,7} ��I�񂾂���flag
  //                 �̏����𖞂������l�̐�
  int dp[11][2][8] = {};
  dp[0][0][0] = 1;

  int nLen = sMaxNum.size();

  for (int i = 0; i < nLen; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      for (int k = 0; k < 8; ++k)
      {
        if (!dp[i][j][k]) continue;

        if (j == 1)                    // small ([0, 9] ���琔����I�ׂ�)��
        {
          if (!k) dp[i + 1][1][0] += dp[i][1][0];            // nothing

          dp[i + 1][1][k | 1] += dp[i][1][k];                // +3
          dp[i + 1][1][k | 2] += dp[i][1][k];                // +5
          dp[i + 1][1][k | 4] += dp[i][1][k];                // +7
        }
        else                           // not small ([0, d] ���琔����I�ׂ�)��
        {
          int nDgt = sMaxNum[i] - '0';

          if (!k)        dp[i + 1][1][0]     += dp[i][0][0]; // nothing

          if (nDgt == 3) dp[i + 1][0][k | 1] += dp[i][0][k]; // +3
          if (3 < nDgt)  dp[i + 1][1][k | 1] += dp[i][0][k]; // +3
          if (nDgt == 5) dp[i + 1][0][k | 2] += dp[i][0][k]; // +5
          if (5 < nDgt)  dp[i + 1][1][k | 2] += dp[i][0][k]; // +5
          if (nDgt == 7) dp[i + 1][0][k | 4] += dp[i][0][k]; // +7
          if (7 < nDgt)  dp[i + 1][1][k | 4] += dp[i][0][k]; // +7
        }
      }
    }
  }
/*
  for (int i = 0; i <= nLen; ++i)
     for (int j = 0; j < 2; ++j)
       for (int k = 0; k < 8; ++k)
         if (dp[i][j][k])
         {
           cout << "dp[" << i << "][" << j << "][" << k << "] = (";
           cout << dp[i][j][k] << ")" << endl;
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
