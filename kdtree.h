#ifndef KDTREE_H_
#define KDTREE_H_

#include "point.h"
#include <queue>
#include <vector>
#include <cmath>
#include <limits>

template <typename coords_type,size_t dim>
class kdtree{
  public:
    typedef point<coords_type,dim> pnt;
    kdtree();
    ~kdtree();

    //methods
    bool insert(pnt&);
    point<coords_type,dim>& search(const pnt&);
    void print();
  private:
    struct node{
      node(const pnt& p):_point(p){}
      coords_type get(size_t ind){ return _point.get(ind);}
      pnt _point;
      node* left;
      node* right;
      int depth;
    };
    node* root;
    void build();
    void delete_children(node*);
    long double distanceEuclid(node*,const pnt&);

};
#include "kdtree.tpp"

#endif
