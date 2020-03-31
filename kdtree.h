#ifndef KDTREE_H_
#define KDTREE_H_

#include "point.h"
#include <queue>
#include <vector>

template <typename coords_type,size_t dim>
class kdtree{
  public:
    typedef point<coords_type,dim> pnt;
    kdtree();
    ~kdtree();

    //methods
    bool insert(pnt&);
    int search(const std::vector<std::pair<coords_type,coords_type>>&);
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

};
#include "kdtree.tpp"

#endif
