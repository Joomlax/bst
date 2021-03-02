// Not included #include 
#include "implement.cpp"
#include <iostream>

int main() {
    
    // Another tree for try comparisions
    int a = 123;
    while(a!=9) {
        std::cout<<"Enter 1 for inserting: "<<std::endl;
        std::cout<<"Enter 2 for checking empty: "<<std::endl;
        std::cout<<"Enter 3 for print inorder "<<std::endl;
        std::cout<<"Enter 4 for searching: "<<std::endl;
        std::cout<<"Enter 5 for sort as postorder: "<<std::endl;
        std::cout<<"Enter 6 for try comparision overload: "<<std::endl;
        std::cout<<"Enter 7 for printing(operator overload ostream): "<<std::endl;
        std::cout<<"Enter 9 for exit: "<<std::endl;
        std::cin>>a;
        switch(a) {
            case 1:
                int b;
                std::cout<<"Enter push value: "<<std::endl;
                std::cin>>b;
                tree.push(b);
                std::cout<<b<<" is inserted to tree!"<<std::endl;
                break;
            case 2:
                if(tree.isEmpty()) {
                    std::cout<<"Tree is empty!"<<std::endl;
                }else {
                    std::cout<<"Tree is not empty!"<<std::endl;
                }
                break;
            case 3:
                tree.inorder(tree.root);
                break;
            case 4:
                int x;
                std::cout<<"Please enter searching value: ";
                std::cin>>x;
                tree.search(x);
                break;
            case 5:
                tree.postorder(tree);
                break;
            case 6:
                 /*
                Try for comparision overloading
                */

                if(t1==tree) {
                    std::cout<<"Sa";
                }else {
                    std::cout<<"As";
                }
                
                break;
            case 7:
            //Try for ostream overloading
                std::cout<<tree.root;
                break;
        }
    }
    
}