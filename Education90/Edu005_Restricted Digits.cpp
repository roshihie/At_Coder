#include <bits/stdc++.h>
using namespace std;
using llong = long long;

llong N, B, K;
vector<llong> vC;

constexpr int MOD = 1e9 + 7;   // MOD
constexpr int LOG = 62;        // N の対数

void input()
{
  cin >> N >> B >> K;
  vC.resize( K );

  for ( llong& num : vC )
    cin >> num;
}

vector<llong> calcDoubling( const vector<llong>& vdpDbli,
                            const vector<llong>& vdpDblj,
                            llong tj )
{
  // dp[i] と dp[j] を掛け合わせて dp[i+j] を得る処理
  // tj: 10^j を B で割ったあまり
  vector<llong> vRes( B );

  for ( llong k = 0; k < B; ++k )
    for ( llong l = 0; l < B; ++l )
    {
      vRes[ ( k * tj + l ) % B ] += vdpDbli[k] * vdpDblj[l];
      vRes[ ( k * tj + l ) % B ] %= MOD;
    }

  return vRes;
}

llong calcCntMultipleB()
{
  // vTen[i]: 10^(2^i) を B で割ったあまり
  vector<llong> vTen(LOG);
  vTen[0] = 10 % B; 

  for ( int i = 1; i < LOG; ++i )
    vTen[i] = ( vTen[i - 1] * vTen[i - 1] ) % B;

  // dp[2^i][r] を doubling[i][r](=vvdpDbl[i][r]) で書くことにする
  vector<vector<llong>> vvdpDbl( LOG, vector<llong>( B ));

  // 初期化 (doubleing[0] := dp[1])
  for ( llong num : vC )
    vvdpDbl[0][ num % B ] += 1;

  // ダブリング
  for ( int i = 1; i < LOG; ++i )
    vvdpDbl[i] = calcDoubling( vvdpDbl[i - 1], vvdpDbl[i - 1], vTen[i - 1] );

  // ダブリングした結果をもとに答えを求める
  vector<llong> vRes( B );
  vRes[0] = 1;

  for ( int each = 0; each < LOG; ++each )
    // N を二の冪乗の積で表すときに、2^i を含むかどうか
    if ( N & ( 1LL << each ))
      vRes = calcDoubling( vRes, vvdpDbl[each], vTen[each] );

  return vRes[0];
}
  
int main()
{
  input();
  cout << calcCntMultipleB() << endl;

  return 0;
}
