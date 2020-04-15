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
    int x=rand()%400+1;
    int y=rand()%400+1;
    point<int,2> p={x,y};
    k.insert(p);
  }

  k.print();
  vector<pair<int,int>> v={{3,50},{44,100}};
  point<int,2> p={100,200};
  //Devuelve el punto mas cercano al punto que enviocj:w
  point<int,2> ans=k.search(p);
  cout<<ans<<endl;




  return 0;
}
