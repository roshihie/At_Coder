#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnProblm)
{
  int nProblmSiz;
  cin >> nProblmSiz;
  rvnProblm.resize(nProblmSiz);

  for (int& rnProblm : rvnProblm)
    cin >> rnProblm;
}
  
int calcDevPgmCnt(const vector<int>& cnrvnProblm)
{
  vector<int> vnSrtProblm(cnrvnProblm);
  sort(begin(vnSrtProblm), end(vnSrtProblm));

  int n = vnSrtProblm.size() / 2;
  return (vnSrtProblm[n] - vnSrtProblm[n - 1]);
}
  
int main()
{
  vector<int> vnProblm;

  input(vnProblm);
  cout << calcDevPgmCnt(vnProblm) << endl;

  return 0;
}
