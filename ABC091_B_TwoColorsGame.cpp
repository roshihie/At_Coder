#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<string>& rvsBlue, vector<string>& rvsRed)
{
  int nBluelSiz;
  cin >> nBluelSiz;

  rvsBlue.resize(nBluelSiz);
  for (string& rsBlue : rvsBlue)
    cin >> rsBlue;

  int nRedSiz;
  cin >> nRedSiz;

  rvsRed.resize(nRedSiz);
  for (string& rsRed : rvsRed)
    cin >> rsRed;
}

int fnPointCount(const vector<string>& cnrvsBlue, 
                 const vector<string>& cnrvsRed  )
{
  map<string, int> mpCounter;

  for (string sBlue : cnrvsBlue)
    mpCounter[sBlue]++;

  for (string sRed : cnrvsRed)
    mpCounter[sRed]--;

  vector<int> vnNum;
  for (pair<const string, int> PCounter : mpCounter)
    vnNum.push_back(PCounter.second);

  auto itNum = max_element(begin(vnNum), end(vnNum));
  int nMaxCnt = max(0, *itNum);

  return nMaxCnt;
}

int main()
{
  vector<string> vsBlue;
  vector<string> vsRed;

  fnInput(vsBlue, vsRed);
  cout << fnPointCount(vsBlue, vsRed) << endl;

  return 0;
}
