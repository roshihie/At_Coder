#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvRate)
{
  int exp;
  cin >> exp;
  rvRate.resize( 1 << exp );

  for (int& rRate : rvRate)
    cin >> rRate;
}

int calc2ndMax(const vector<int>& crvRate)
{
  auto itBgn = begin(crvRate);
  auto itMid = itBgn + crvRate.size() / 2;
  auto itLeftMax  = max_element( itBgn, itMid );
  auto itRightMax = max_element( itMid, end(crvRate) );

  if ( *itLeftMax < *itRightMax )
    return itLeftMax  - itBgn + 1;
  else
    return itRightMax - itBgn + 1;
}
  
int main()
{
  vector<int> vRate;
  input(vRate);
  cout << calc2ndMax(vRate) << endl;

  return 0;
}
