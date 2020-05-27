#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<string>& rvsStr)
{
  int nStrSiz;
  cin >> nStrSiz;
  rvsStr.resize(nStrSiz);

  for (string& rsStr : rvsStr)
    cin >> rsStr;
}
  
int64_t fnAnagramCnt(const vector<string>& cnrvsStr)
{
  vector<string> vsSortStr(cnrvsStr);

  for (string& rsSortStr : vsSortStr)
    sort(begin(rsSortStr), end(rsSortStr));

  int64_t nAnagramCnt = 0;
  map<string, int> mpSortStr;

  for (string sSortStr : vsSortStr)
  {
    nAnagramCnt += mpSortStr[ sSortStr ];
    mpSortStr[ sSortStr ]++;
  }
  return nAnagramCnt;
}
  
int main()
{
  vector<string> vsStr;

  fnInput(vsStr);
  cout << fnAnagramCnt(vsStr) << endl;

  return 0;
}
