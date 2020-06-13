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

  for (int n = 0; n < nEntrySiz; n++)
    if (n % 2 == 1)  nStrength += cnrvnEntry[n];

  return nStrength;
}

int main()
{
  vector<int> vnEntry;

  fnInput(vnEntry);
  cout << fnStrengthChk(vnEntry) << endl;

  return 0;
}
