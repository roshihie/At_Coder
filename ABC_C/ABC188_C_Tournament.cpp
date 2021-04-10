#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnRate)
{
  int nRatePower;
  cin >> nRatePower;
  rvnRate.resize( 1 << nRatePower );

  for (int& rnRate : rvnRate)
    cin >> rnRate;
}

int calc2ndRate(const vector<int>& cnrvnRate)
{
  auto it1stHalf = max_element( begin(cnrvnRate), 
                                begin(cnrvnRate) + cnrvnRate.size() / 2 );
  auto it2ndHalf = max_element( begin(cnrvnRate) + cnrvnRate.size() / 2, 
                                end(cnrvnRate) );

  if (*it1stHalf < *it2ndHalf)
    return it1stHalf - begin(cnrvnRate) + 1;
  else
    return it2ndHalf - begin(cnrvnRate) + 1;
}
  
int main()
{
  vector<int> vnRate;
  input(vnRate);
  cout << calc2ndRate(vnRate) << endl;

  return 0;
}
