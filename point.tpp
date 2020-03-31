template<typename coords_type,size_t dim>
point<coords_type,dim>::point(std::array<coords_type,dim>& x):coords(x){
  if(x.size()!=dim)
    throw std::logic_error("Error founded: dim is not equal to array size");
}

template<typename coords_type,size_t dim>
point<coords_type,dim>::point(std::initializer_list<coords_type> l){
  if(l.size()!=dim)
    throw std::logic_error("Error founded: dim is not equal to array size");
  std::copy_n(l.begin(),dim,coords.begin());
}

template<typename coords_type,size_t dim>
coords_type point<coords_type,dim>::get(size_t ind) const{
  return coords[ind];
}





