#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnDisk)
{
  int nDiskSiz;
  cin >> nDiskSiz;

  rvnDisk.resize(nDiskSiz);
  for (int i = 0; i < nDiskSiz; i++)
    cin >> rvnDisk[i];
}

int fnDiskCount(const vector<int>& cnrvnDisk)
{
  set<int> seDisk;

  for (int nDisk : cnrvnDisk)
    seDisk.insert(nDisk);

  return seDisk.size();
}

int main()
{
  vector<int> vnDisk;
  fnInput(vnDisk);
  cout << fnDiskCount(vnDisk) << endl;

  return 0;
}
