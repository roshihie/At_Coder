#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<string>& rvsStr)
{
  int nStrSiz;
  cin >> nStrSiz;
  rvsStr.resize(nStrSiz);

  for (string& rsStr : rvsStr)
    cin >> rsStr;
}
  
llong calcAnagramCnt(const vector<string>& cnrvsStr)
{
  vector<string> vsSortStr(cnrvsStr);

  for (string& rsSortStr : vsSortStr)
    sort(begin(rsSortStr), end(rsSortStr));

  llong nAnagramCnt = 0;
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

  input(vsStr);
  cout << calcAnagramCnt(vsStr) << endl;

  return 0;
}
