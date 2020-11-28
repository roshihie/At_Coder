#include <bits/stdc++.h>
using namespace std;

void input(int& rnSelSiz, vector<int>& rvnHeight)
{
  int nHeightSiz;
  cin >> nHeightSiz >> rnSelSiz;
  rvnHeight.resize(nHeightSiz);

  for (int& rnHeight : rvnHeight)
    cin >> rnHeight;

  sort (begin(rvnHeight), end(rvnHeight));
}

int calcMinDiffHeight(int nSelSiz, const vector<int>& cnrvnHeight)
{
  int nMinDiffHeight = INT_MAX;

  for (int nx = 0; nx < cnrvnHeight.size() - (nSelSiz - 1); ++nx)
    nMinDiffHeight = min(nMinDiffHeight, cnrvnHeight[nx + (nSelSiz - 1)] - cnrvnHeight[nx]);  
  
  return nMinDiffHeight;
}
 
int main()
{
  int nSelSiz;
  vector<int> vnHeight;

  input(nSelSiz, vnHeight);
  cout << calcMinDiffHeight(nSelSiz, vnHeight) << endl;

  return 0;
}
