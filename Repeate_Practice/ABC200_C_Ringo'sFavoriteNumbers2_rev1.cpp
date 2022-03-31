#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rnRem)
{
  int remSiz;
  cin >> remSiz;
  rnRem.resize(remSiz);

  for (int& rRem : rnRem)
  {
    cin >> rRem;
    rRem %= 200;
  }
}

llong calc200MultCnt(const vector<int>& crnRem)
{
  llong cnt200Mult = 0;
  map <int, int> mpNum;

  for (int rem v crnRem )
    ++mpNum[rem];
  
  for (auto Pnum : mpNum)
    cnt200Mult += (llong)Pnum.second * ( Pnum.second - 1 ) / 2;

  return cnt200Mult;
}

int main()
{
  vector <int> nRem;

  input(nRem);
  cout << calc200MultCnt(nRem) << endl;
  return 0;
}
