#ifndef _TREE_H_
#define _TREE_H_


class Tree {
    //struct TreeNode;
    struct TreeNode {
        int data;
        // bool visited = false;
        TreeNode *left, *right, *parent;
        enum class Kind {Left, Right, Root};
        Kind kind;
        TreeNode(int data, Kind kind, TreeNode *parent, TreeNode *left = nullptr, TreeNode *right = nullptr):
        data{data}, parent{parent}, left{left}, right{right}, kind{kind} {}
        ~TreeNode() {
            delete left;
            delete right;
        }
    };
    TreeNode *root;
    
public:
    Tree();
    ~Tree();
    
    void insert (int data);
    
    //class Iterator;
    class Iterator{
        TreeNode* current;
        TreeNode* root;
    public:
        //get the root in ctor so I can access it
        Iterator(TreeNode *start,TreeNode*root) : current{start}{
            this->root=root;
        }
        int& operator*(){return current->data;}
        //call that inorder func
        Iterator& operator++(){
            //std::cout<<"called"<<std::endl;
            inorder();
            
            return *this;
        }
        //not really doing anything here
        Iterator& operator--(){
            --current;
            return *this;
        }
        bool operator ==(const Iterator& other) const { return current == other.current;}
        bool operator !=(const Iterator& other) const { return !(*this == other);}
        //check different cases, always starting at the left most node of a branch
        //if it's the right most, I get a helper function to go back topper level
        //begin at the smallest element
        void inorder(){
            if(current->right==nullptr){
                if(current==root){
                    current =nullptr;
                    return;
                }
                if (current->parent->left==current){
                    current= current->parent;
                    return;
                }
                else if (current->parent->right == current){
                helpback();
                return;
            }
            }else if ( current->right!=nullptr){
                if (current->right->left!=nullptr){
                    current = current->right->left;
                    endofleft();
                    return;
                }else if(current->right->left==nullptr){
                    current = current->right;
                    return;
                }
            }
            
        }
        //go back to the topper lever where the node has greater value of the current one
        //so that node has not been printed
        void helpback(){
            int temp = current->data;
            while(current->parent->data<temp){
                current=current->parent;
                if(current==root){
                    current=nullptr;
                    return;
                }
            }
            current = current->parent;
        }
        //every branch that has a left branch, always go to the left most
        void endofleft(){
            while(current->left!=nullptr){
                current = current->left;
            }
        }
    };
    
    
    
    Iterator begin();
    Iterator end();
    //void inorder();
};

#endif
