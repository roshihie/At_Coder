#include <bits/stdc++.h>
using namespace std;

void input(string& rsMaxNum)
{
  cin >> rsMaxNum;
}

int digitDp(string sMaxNum)
{
  // dp[nPos][nSmall][nDgt3][nDgt5][nDgt7] :=
  //    nPos  : 上位 nPos 桁目まで決定
  //    nSmall: small(数字を自由に選べる)か
  //    nDgt3 : 上位 nPos 桁までで 3 を選択したかflag
  //    nDgt5 : 上位 nPos 桁までで 5 を選択したかflag
  //    nDgt7 : 上位 nPos 桁までで 7 を選択したかflag
  //                             の条件を満たす数値の数
  const vector<int> cnvnDgt = {0, 3, 5, 7};
  int nLen = sMaxNum.size();

  int dp[nLen + 1][2][2][2][2] = {};
  dp[0][0][0][0][0] = 1;

  for (int nPos = 0; nPos < nLen; ++nPos)
  {
    int nMaxDgt = sMaxNum[nPos] - '0';

    for (int nSmall = 0; nSmall < 2; ++nSmall)
      for (int nDgt3 = 0; nDgt3 < 2; ++nDgt3)
        for (int nDgt5 = 0; nDgt5 < 2; ++nDgt5)
          for (int nDgt7 = 0; nDgt7 < 2; ++nDgt7)
            for (int nx = 0; nx < cnvnDgt.size(); ++nx)
            {
              if ( !nSmall && nMaxDgt < cnvnDgt[nx] ) 
                break;
              if (( nDgt3 || nDgt5 || nDgt7) && !cnvnDgt[nx] )
                continue;

              int nTrgSmall = nSmall || (cnvnDgt[nx] < nMaxDgt);
              int nTrgDgt3  = nDgt3  || (cnvnDgt[nx] == 3);
              int nTrgDgt5  = nDgt5  || (cnvnDgt[nx] == 5);
              int nTrgDgt7  = nDgt7  || (cnvnDgt[nx] == 7);
              dp[ nPos + 1 ][ nTrgSmall ][ nTrgDgt3 ][ nTrgDgt5 ][ nTrgDgt7 ]
                += dp[nPos][nSmall][nDgt3][nDgt5][nDgt7];
            }
  }
  return dp[nLen][0][1][1][1] + dp[nLen][1][1][1][1];
}

int main()
{
  string sMaxNum;

  input(sMaxNum);
  cout << digitDp(sMaxNum) << endl;
  
  return 0;
}
