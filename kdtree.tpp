template<typename coords_type,size_t dim>
kdtree<coords_type,dim>::kdtree(){
    root=nullptr;
}

template<typename coords_type,size_t dim>
void kdtree<coords_type,dim>::delete_children(node* p){
  if(p->left)
    delete_children(p->left);
  if(p->right)
    delete_children(p->right);

  delete p;
}

template<typename coords_type,size_t dim>
kdtree<coords_type,dim>::~kdtree(){
  if(root)
    delete_children(root);
}

template<typename coords_type,size_t dim>
bool kdtree<coords_type,dim>::insert(pnt& p){ 
  if(root){
    node*tmp=root;
    node* new_node=new node(p);
    int i=0;
    while(tmp){
      if(tmp->get(i%dim)>p.get(i%dim)){
        if(!tmp->left){
          tmp->left=new_node;
          new_node->depth=i+1;
          break;
        }
        tmp=tmp->left;
      }
      else{
        if(!tmp->right){
          tmp->right=new_node;
          new_node->depth=i+1;
          break;
        }
        tmp=tmp->right;
      }
      i++;
    }
  }
  else{
    root=new node(p);
    root->left=nullptr;
    root->right=nullptr;
    root->depth=0;
  }
  return true;
}

template<typename coords_type,size_t dim>
long double kdtree<coords_type,dim>::distanceEuclid(node* i,const pnt& j){
  long double dist=0;
  for(size_t ind=0;ind<dim;ind++){
    dist+=pow(i->get(ind)-j.get(ind),2);
  }
  return sqrtl(dist);
}

template<typename coords_type,size_t dim>
point<coords_type,dim>& kdtree<coords_type,dim>::search(const pnt& x){


  if(!root)
    throw std::runtime_error("El kdtree se encuentra vacio");

  node* p=root;
  std::queue<node*> q;
  q.push(p);
  int ind=-1;
  long double curr_dist=std::numeric_limits<long double>::max();
  node *curr_ans;
  
 bool faro;
  while(!q.empty()){
    p=q.front();
    q.pop();
    
    long double dist=distanceEuclid(p,x);
    if(dist<=curr_dist){
      curr_ans=p;
      curr_dist=dist;
    }
    ind++;
    if(p->get(ind%dim)<x.get(ind%dim)){
      if(p->right)
        q.push(p->right);
      else if(p->left)
        q.push(p->left);
    }
    else{
      if(p->left)
        q.push(p->left);
      else if(p->right)
        q.push(p->right);
    }
    
  }
  
  return curr_ans->_point;
}

template<typename coords_type,size_t dim>
void kdtree<coords_type,dim>::print(){
  
  if(root){
    int depth_tmp=0;
    std::queue<node*> q;
    q.push(root);
    while(!q.empty()){
      node * p=q.front();
      q.pop();
      if(p->depth==depth_tmp){
        for(int i=0;i<5-depth_tmp;i++)
          std::cout<<" ";
      }
      else{
        std::cout<<"\n";
        depth_tmp++;
      }
      std::cout<<"("<<p->depth<<")"<<p->_point;
      if(p->left)
        q.push(p->left);
      if(p->right)
        q.push(p->right);
    }
  }

  std::cout<<"\n end printing \n";
}

template<typename coords_type,size_t dim>
void kdtree<coords_type,dim>::build(){}
