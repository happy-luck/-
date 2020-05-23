#include <iostream>
using namespace std;

struct node
{
    int val;
    pnode lchild;
    pnode rchild;
};
// 查找
pnode search_BST(pnode p,int x){
    bool solve = false;
    while(p && !solve){
        if(x==p->val){
            solve = true;
        }
        else if(x<p->val)
        {
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
    if(p==NULL){
        cout << "没有找到" << x << endl;
    }
    return p;
}
// 插入
pnode insert_BST(pnode & root,int x){
    if(root == NULL){
        pnode p = (pnode) malloc(LEN);
        p->val = x;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
    }
    else if(x<root->val)
    {
        root->lchild = insert(root->lchild,x);
    }
    else{
        root->rchild = insert(root->rchild,x);
    }
    return root;
}

// 删除
bool delete_BST(pnode p,int x){
    bool find = false;
    pnode q;
    p = BT;
    while(p && !find){
        if(x==p->val){
            find = true;
        }
        else if(x<p->val){
            q = p;
            p = p->lchild;
        }
        else{
            q = p;
            p = p->rchild;
        }
    }
    if(p==NULL){
        cout << "没有找到" << x << endl;
    }
    if(p->lchild==NULL &&p->rchild==NULL){
        if(p==BT){
            BT==NULL;
        }
        else if(q->lchild==p){
            q->lchild == NULL;
        }
        else{
            q->rchild == NULL;
        }
        free(p);
    }
    else if(p->lchild==NULL || p->rchild==NULL){
        if(p==BT){
            if(p->lchild==NULL){
                BT = p->rchild;
            }
            else{
                BT = p->lchild;
            }
        }
        else{
            if(q->lchild==p && p->lchild){
                q->lchild = p->lchild;
            }
            else if(q->lchild==p && p->rchild){
                q->lchild = p->rchild;
            }
            else if(q->rchild==p && p->lchild){
                q->rchild = p->lchild;
            }else{
                q->rchild = p->rchild;
            }
        }
        free(p);
    }
    else{
        pnode t = p;
        pnode s = p->lchild;
        while (s->rchild)
        {
            t = s;
            s = s->rchild;
        }
        p->val = s->val;
        if(t==p){
            p->lchild = s->lchild;
        }
        else{
            t->rchild = s->lchild;
        }
        free(s); 
    }
    return find;
}

// 前序遍历
void Preorder(BiTree* T){
    if(!T){
        return;
    }
    visit(T);
    Preorder(T->lchild);
    Preorder(T->rchild);
}

// 中序遍历
void Inorder(BiTree* T){
    if(!T){
        return;
    }
    Inorder(T->lchild);
    visit(T);
    Inorder(T->rchild);
}

// 后序遍历
void Postorder(BiTree* T){
    if(!T){
        return;
    }
    Postorder(T->lchild);
    Postorder(T->rchild);
    visit(T);
}
// 根据前序和中序遍历得到后序遍历
void InPre2Post(char* inorder, char* preorder,int length){
    TreeNode* node = new TreeNode;
    node->elem = *preorder;
    int nRoot = 0;
    for(;nRoot<length;nRoot++){
        if(inorder[nRoot]==*preorder){
            break;
        }
    }
    InPre2Post(inorder,preorder+1,nRoot);
    InPre2Post(inorder+nRoot+1,preorder+nRoot+1,length-(nRoot+1));
    cout<<node->elem<<endl;
    return;
}

// 根据后序和中序遍历得到前序遍历
void InPost2Pre(char* inorder, char* postorder,int length){
    TreeNode* node = new TreeNode;
    node->elem = *(postorder+length-1);
    cout<<node->elem<<endl;
    int nRoot = 0;
    for(;nRoot<length;nRoot++){
        if(inorder[nRoot]== *(postorder+length-1)){
            break;
        }
    }
    InPost2Pre(inorder,postorder+1,nRoot);
    InPost2Pre(inorder+nRoot+1,postorder+nRoot,length-(nRoot+1));
}

