#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<string>& rvsStr)
{
  int nStrSiz;
  cin >> nStrSiz;
  rvsStr.resize(nStrSiz);

  for (string& rsStr : rvsStr)
  {
    cin >> rsStr;
    sort(begin(rsStr), end(rsStr));
  }
}
  
llong calcAnagramCnt(const vector<string>& cnrvsStr)
{
  llong nAnagramCnt = 0;
  map<string, int> mpAnagram;

  for (string sStr : cnrvsStr)
    nAnagramCnt += mpAnagram[ sStr ]++;

  return nAnagramCnt;
}
  
int main()
{
  vector<string> vsStr;

  input(vsStr);
  cout << calcAnagramCnt(vsStr) << endl;

  return 0;
}
