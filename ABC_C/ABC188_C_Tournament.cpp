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
  auto bgn2nd = begin(crvRate) + crvRate.size() / 2;
  auto it1stMax = max_element(begin(crvRate), bgn2nd);
  auto it2ndMax = max_element(bgn2nd, end(crvRate));
 
  if ( *it1stMax < *it2ndMax )
    return it1stMax - begin(crvRate) + 1;
  else
    return it2ndMax - begin(crvRate) + 1;
}
  
int main()
{
  vector<int> vRate;
  input(vRate);
  cout << calc2ndMax(vRate) << endl;

  return 0;
}
