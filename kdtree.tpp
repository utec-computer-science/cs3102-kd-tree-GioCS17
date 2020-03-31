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
int kdtree<coords_type,dim>::search(const std::vector<std::pair<coords_type,coords_type>>& v){

  int cont=0;

  if(!root)
    return cont;

  node* tmp=root;
  std::queue<node*> q;
  q.push(tmp);
  node* p;
  
 bool faro;
  while(!q.empty()){
    p=q.front();
    q.pop();
    faro=true;
    
    for(int i=0;i<dim;i++){
      if(v[i].first<=p->get(i) && v[i].second>=p->get(i))
        continue;
      faro=false;
    }
    if(faro)
      cont++;
    if(v[p->depth%dim].first<=p->get(p->depth%dim) && v[p->depth%dim].second>=p->get(p->depth%dim)){
      if(p->left)
        q.push(p->left);
      if(p->right)
        q.push(p->right);
    }
    else if(v[p->depth%dim].first>=p->get(p->depth%dim)){
      if(p->right)
        q.push(p->right);
    }
    else if(v[p->depth%dim].second<p->get(p->depth%dim)){
      if(p->left)
        q.push(p->left);
    }
  }
  
  return cont;
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
