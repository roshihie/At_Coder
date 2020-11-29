#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(vector<int>& rvnEntry)
{
  int nEntrySiz;
  cin >> nEntrySiz;
  rvnEntry.resize(3 * nEntrySiz);

  for (int& rnEntry : rvnEntry)
    cin >> rnEntry;

  sort(begin(rvnEntry), end(rvnEntry), greater<int>());
}

llong fnStrengthChk(const vector<int>& cnrvnEntry)
{
  llong nStrength = 0;
  int nEntrySiz = cnrvnEntry.size() * 2 / 3;

  for (int nx = 0; nx < nEntrySiz; ++nx)
    if (nx % 2 == 1)  nStrength += cnrvnEntry[nx];

  return nStrength;
}

int main()
{
  vector<int> vnEntry;

  fnInput(vnEntry);
  cout << fnStrengthChk(vnEntry) << endl;

  return 0;
}
