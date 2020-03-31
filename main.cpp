#include<iostream>
#include "kdtree.h"
#include "point.h"
#include<time.h>
#include<vector>

using namespace std;

int main(){

  point<int,2> arr[]={{2,3},{4,5}};
  int n=10;
  srand(time(NULL));
  kdtree<int,2> k;
  for(int i=0;i<n;i++){
    int x=rand()%100+1;
    int y=rand()%100+1;
    //int z=rand()%100+1;
    //point<int,3> p={x,y,z};
    point<int,2> p={x,y};
    //cout<<p<<endl;
    k.insert(p);
  }

  k.print();
  vector<pair<int,int>> v={{3,50},{44,100}};
  cout<<k.search(v)<<endl;




  return 0;
}
