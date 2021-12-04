#include <bits/stdc++.h>
using namespace std;

void input( string& rsmaxNum )
{
  cin >> rsmaxNum;
}

int digitDp( string smaxNum )
{
  // dp[pos][small][dgt3][dgt5][dgt7] :=
  //    pos  : ��� pos ���ڂ܂Ō���
  //    small: small(���������R�ɑI�ׂ�)��
  //    dgt3 : ��� pos ���܂ł� 3 ��I��������flag
  //    dgt5 : ��� pos ���܂ł� 5 ��I��������flag
  //    dgt7 : ��� pos ���܂ł� 7 ��I��������flag
  //                               �̏����𖞂������l�̐�
  const vector<int> cvDgt = {0, 3, 5, 7};
  int len = smaxNum.size();

  int dp[len + 1][2][2][2][2] = {};
  dp[0][0][0][0][0] = 1;

  for ( int pos = 0; pos < len; ++pos )
  {
    int nMaxDgt = smaxNum[pos] - '0';

    for ( int small = 0; small < 2; ++small )
      for ( int dgt3 = 0; dgt3 < 2; ++dgt3 )
        for ( int dgt5 = 0; dgt5 < 2; ++dgt5 )
          for ( int dgt7 = 0; dgt7 < 2; ++dgt7 )
            for ( int x = 0; x < (int)cvDgt.size(); ++x )
            {
              if ( !small && nMaxDgt < cvDgt[x] ) 
                break;
              if (( dgt3 || dgt5 || dgt7 ) && !cvDgt[x] )
                continue;

              int trgSmall = small || (cvDgt[x] < nMaxDgt);
              int trgDgt3  = dgt3  || (cvDgt[x] == 3);
              int trgDgt5  = dgt5  || (cvDgt[x] == 5);
              int trgDgt7  = dgt7  || (cvDgt[x] == 7);
              dp[ pos + 1 ][trgSmall][trgDgt3][trgDgt5][trgDgt7]
                 += dp[pos][small][dgt3][dgt5][dgt7];
            }
  }
  return dp[len][0][1][1][1] + dp[len][1][1][1][1];
}

int main()
{
  string smaxNum;

  input( smaxNum );
  cout << digitDp( smaxNum ) << endl;
  
  return 0;
}
