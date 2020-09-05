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

  for (int i = 0; i < cnrvnHeight.size() - (nSelSiz - 1); i++)
    nMinDiffHeight = min(nMinDiffHeight, cnrvnHeight[i + (nSelSiz - 1)] - cnrvnHeight[i]);  
  
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
