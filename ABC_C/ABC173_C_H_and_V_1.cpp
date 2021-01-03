#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<char>>& rvvcColor, int& rnRemain)
{
  int nySiz, nxSiz;
  cin >> nySiz >> nxSiz >> rnRemain;
  rvvcColor.resize(nySiz);

  for (int ny = 0; ny < rvvcColor.size(); ++ny)
  {
    rvvcColor[ny].resize(nxSiz);

    for (int nx = 0; nx < rvvcColor[ny].size(); ++nx)
      cin >>  rvvcColor[ny][nx];
  }
}

void paintColorRed(int nEach, vector<vector<char>>& rvvcColor)
{
  if (nEach < rvvcColor.size())
  {
    for (int nx = 0; nx < rvvcColor[nEach].size(); ++nx)
      rvvcColor[nEach][nx] = ' ';
  }
  else
  {
    nEach -= rvvcColor.size();
    for (int ny = 0; ny < rvvcColor.size(); ++ny)
      rvvcColor[ny][nEach] = ' ';
  }
}

int calcNumOfCase(const vector<vector<char>>& cnrvvcColor, int nRemain)
{
  int nNumOfCase = 0;
  int nSize = cnrvvcColor.size() + cnrvvcColor[0].size();

  for (int nBit = 0; nBit < ( 1 << nSize ) ; ++nBit)
  {
    vector<vector<char>> vvcColor(cnrvvcColor);

    for (int nEach = 0; nEach < nSize; ++nEach)
      if (nBit & ( 1 << nEach ))
        paintColorRed(nEach, vvcColor);

    int nCntTrg = 0;

    for (int ny = 0; ny < vvcColor.size(); ++ny)
      for (int nx = 0; nx < vvcColor[ny].size(); ++nx)
        if (vvcColor[ny][nx] == '#') ++nCntTrg;

    if (nCntTrg == nRemain) ++nNumOfCase;
  }
  return nNumOfCase;
}
 
int main()
{
  vector<vector<char>> vvcColor;
  int nRemain;

  input(vvcColor, nRemain);
  cout << calcNumOfCase(vvcColor, nRemain) << endl;

  return 0;
}
