#ifndef POINT_H_
#define POINT_H_

#include<vector>
#include<array>
#include<algorithm>

template<typename coords_type, size_t dim>
class point{
  std::array<coords_type,dim> coords;
  public:
    point(std::array<coords_type,dim>&);
    point(std::initializer_list<coords_type>);
    coords_type get(size_t) const;
};

template<typename coords_type, size_t dim>
std::ostream& operator<<(std::ostream& out,const point<coords_type,dim>&p){
  out<<"(";
  for(size_t i=0;i<dim;i++){
    if(i>0)
      out<<" ";
    out<<p.get(i);
  }
  out<<")";
  return out;
}

#include "point.tpp"

#endif
