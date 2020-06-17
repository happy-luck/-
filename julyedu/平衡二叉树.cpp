// 左左情况下的旋转
template<class T>
void AVLTree<T>::SingRotateLeft(TreeNode<T>* &k2){
    TreeNode<T>* k1;
    k1 = k2->lson;
    k2->lson = k1->rson;
    k1->rson = k2;
    k2->hgt = Max(height(k2->lson),height(k2->rson))+1;
    k1->hgt = Max(height(k1->lson),k2->hgt)+1;
}

// 左左情况下的旋转
template<class T>
void AVLTree<T>::SingRotateRight(TreeNode<T>* &k2){
    TreeNode<T>* k1;
    k1 = k2->rson;
    k2->rson = k1->lson;
    k1->lson = k2;
    k2->hgt = Max(height(k2->lson),height(k2->rson))+1;
    k1->hgt = Max(height(k1->rson),k2->hgt)+1;
}

// 左右情况下的旋转
template<class T>
void AVLTree<T>::DoubleRotateLR(TreeNode<T>* &k3){
    SingRotateRight(k3->lson);
    SingRotateLeft(k3);
}

// 右左情况下的旋转
template<class T>
void AVLTree<T>::DoubleRotateRL(TreeNode<T>* &k3){
    SingRotateLeft(k3->rson);
    SingRotateRight(k3);
}

// 插入
template<class T>
void AVLTree<T>::insertpri(TreeNode<T>* &node,T x){
    if(node==NULL){
        node = new TreeNode<T>();
        node->data = x;
        return;
    }
    if(node->data>x){
        insertpri(node->lson,x);
        if(2==height(node->lson)-height(node->rson)){
            if(x<node->lson->data){
                SingRotateLeft(node);
            }
            else{
                DoubleRotateLR(node);
            }
        }
        else if(node->data<x){
            insertpri(node->rson,x);
            if(2==height(node->lson)-height(node->rson)){
                if(x>node->rson->data){
                    SingRotateRight(node);
                }
                else{
                    DoubleRotateRL(node);
                }
            }
        }
        else ++(node->freq);
        node->hgt = Max(height(node->lson),height(node->rson))+1;
    }
}
// 插入接口
template<class T>
void AVLTree<T>::insert(T x){
    insertpri(root,x);
}

// 删除
template<class T>
void AVLTree<T>::Deletepri(TreeNode<T>* &node, T x){
    if(node==NULL)
        return;
    if(x<node->data){
        Deletepri(nodee->lson,x);
        if(2==height(node->rson)-height(node->lson)){
            if(node->rson->lson!=NULL && (height(node->rson->lson)>height(node->rson->rson))){
                DoubleRotateRL(node);
            }else{
                SingRotateRight(node);
            }
        }
    }
    else if(x>node->data){
        Deletepri(node->rson,x);
        if(2==height(node->lson)-height(node->rson)){
            if(node->lson->rson!=NULL && (height(node->lson->rson)>height(node->lson->lson))){
                DoubleRotateLR(node);
            }else{
                SingRotateLeft(node);
            }
        }
    }
    else{
        if(node->lson&&node->rson){
            TreeNode<T>* temp = node->rson;
            while(temp->lson!=NULL){
                temp = temp->lson;
            }
            node->data = temp->data;
            node->freq = temp->freq;
            Deletepri(node->rson,temp->data);
            if(2==height(node->lson)-height(node->rson)){
                if(node->lson->rson!=NULL && (height(node->lson->rson)>height(node->lson->lson))){
                    DoubleRotateLR(node);
                }else{
                    SingRotateLeft(node);
                }
            }
        }
        else{
            TreeNode<T>* temp = node->rson;
            if(node->lson==NULL){
                node = node->rson;
            }
            else if(node->rson==NULL){
                node=node->lson;
            }
            delete(temp);
            temp=NULL;
        }
    }
    if(node==NULL){
        return;
    }
    node->hgt = Max(height(node->lson),height(node->rson))+1;
    return;
}
// 删除接口
template<class T>
void AVLTree<T>::Delete(T x){
    Deletepri(root,x);
}