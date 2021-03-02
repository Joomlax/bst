
#include "interface.h"

template<class T_>
struct Node {
    T_ value;
    T_ *left;
    T_ *right;
};
template<class T_>
class Tree : public Interface {
    
    public:
        T_ *root;

        Tree() {
            root=NULL;
        }
        
        
        //For the Implement.cpp functions
        
        void inorder(struct Node<T_> *temp) const;
        //Overloaded inorder
        void inorder(T_ *temp) const;
        //Overloaded inorder
        void postorder(struct Node<T_> *temp) const;
        void pop(struct Node<T_>* root, struct Node<T_> key);
        void printTree(T_* temp) const;
        
        Node<T_> *search(T_ key, struct Node<T_> *leaf) const;
        Node<T_> *search(T_ key) const;
        T_ *minValueNode(T_* node) const;
        
        //Pushing 
        virtual void push(struct Node<T_> key, struct Node<T_>* leaf) {
            if(dynamic_cast<T_>key < (T_)leaf->value) { //Given 
                if(leaf->left!=NULL) {
                    Tree<T_>::push(key, leaf->left);
                }else {
                    leaf->left = new T_;
                    leaf->left->value= key;
                    leaf->left->left= NULL; // left child of the child node
                    leaf->left->right= NULL; // right child of the child node
                }
                }else if(key>=leaf->value) {
                    if(leaf->right!=NULL) {
                        Tree::push(key,leaf->right);
                    }else {
                        leaf->right = new T_;
                        leaf->right->value = key;
                        leaf->right->left=NULL;// left child of the child node
                        leaf->right->right=NULL;  // right child of the child node
                    }
                }
        }
        
        //Overloading Push
        virtual void push(T_ key) { //Overloading of push func.
            if(root!=NULL) {
                push(key, root);
            }else {
                root = new T_;
                root->value =key ;
                root->left = NULL;
                root->right = NULL;
            }
        }
       //For checking is it empty or not
        virtual bool isEmpty(){
            if(root==NULL){
                return true;
            }else{
                    return false;
            }
            
        } 

};
