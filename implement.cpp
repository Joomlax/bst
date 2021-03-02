#include "impl.h"


template<class T_>
void Tree<T_>::inorder(struct Node<T_> *temp) const   {
    if(temp!=NULL) {
        inorder(temp->left);
        std::cout<<temp->value<<std::endl;
        inorder(temp->right);
    }
}

template<class T_>
void Tree<T_>::printTree(T_* temp) const {
            if(root!=NULL){
                printTree(root->left);
                printTree(root->right);
                std::cout<<root->value<<std::endl;
            }
        }

template<class T_>
void Tree<T_>::postorder(struct Node<T_> *temp) const {
    if(temp!=NULL) {
        postorder(temp->left);
        postorder(temp->right);
        std::cout<<temp->value<<std::endl;
        
    }
    
    
}

template<class T_>
void Tree<T_>::pop(struct Node<T_>* root, struct Node<T_> key)  {
            if(root==NULL)
                return root;
            if(key < root->value) {
                root->left = pop(root->left, key);
            }else if(key > root->value) {
                root->right = pop(root->right, key);
            }else {
                if(root->left==NULL){
                    T_ *temp = root->right;
                    free(root);
                    return temp;
                }else if(root->right == NULL) {
                    T_ *temp = root->left;
                    free(root);
                    return temp;
                }
                T_ *temp = minValueNode(root->right);
                root->value = temp->value;
                root->right = pop(root->right, temp->value); 
            }
        }

       

        template<class T_>
        Node<T_>* Tree<T_>::search(T_ key, struct Node<T_> *leaf) const { //Overloaded Search function
                if(key==leaf->value) {
                    std::cout<<"\n Finded! Its memory code is:"<<leaf<<std::endl;
                    return leaf;
                }else if(key < leaf->value) {
                    return search(key, leaf->left);
                }else if(key>leaf->value){
                    return search(key, leaf->right);
                }else {
                    std::cout<<"It is not in this tree";
                    return NULL;
                }
            
        }

         template<class T_>
        Node<T_>* Tree<T_>::search(T_ key) const {
            if(root!=NULL) {
                search(key,root);                
            }else{
                return NULL;
            }
            
        }

        
        template<class T_>
        T_* Tree<T_>::minValueNode(T_* node) const {
            T_* current = node;
            while(current && current->left != NULL) {
                current = current->left;
            }
            return current;
        }

Tree<int> tree;

Tree<int> t1;



/*
    Ostream overloaded! 
    It is overloaded in implement.cpp because it needs to take 
    tree object!
 */


/*
template<class T_>
std::ostream& operator <<(std::ostream& os, T_* temp) {
    if(temp!=NULL) {
        tree.postorder(temp->left);
        tree.postorder(temp->right);
        os<<temp->value<<std::endl;
    }
    return os;
}
*/


//== Operator Overloading !
template<class T_>
bool operator == (const Tree<T_> &t1, const Tree<T_> &t2) {
    if(t1.root==t2.root) {
        return true;
    }
    else {
        return false;
    }
}


//!= Operator Overloading !
template<class T_>
bool operator != (const Tree<T_> &t1, const Tree<T_> &t2) {
    if(t1.root!=t2.root) {
        return true;
    }
    else {
        return false;
    }
}

/*
    Ostream overloaded! 
    It is overloaded in implement.cpp because it needs to take 
    tree object!
 */
