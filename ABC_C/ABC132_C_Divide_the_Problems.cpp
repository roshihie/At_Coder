#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnProblm)
{
  int nProblmSiz;
  cin >> nProblmSiz;
  rvnProblm.resize(nProblmSiz);

  for (int& rnProblm : rvnProblm)
    cin >> rnProblm;
}
  
int fnDevProblmCnt(const vector<int>& cnrvnProblm)
{
  vector<int> vnSrtProblm(cnrvnProblm);
  sort(begin(vnSrtProblm), end(vnSrtProblm));

  int n = vnSrtProblm.size() / 2;
  return (vnSrtProblm[n] - vnSrtProblm[n - 1]);
}
  
int main()
{
  vector<int> vnProblm;

  fnInput(vnProblm);
  cout << fnDevProblmCnt(vnProblm) << endl;

  return 0;
}
