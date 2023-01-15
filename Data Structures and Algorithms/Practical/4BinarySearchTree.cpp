#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    Node *root;

    public:
    BST(){
        root = NULL;
    }

    Node *insertBST(Node*root,int data){
        if (root ==NULL)
        {
            return new Node(data);
        }
        if(data<root->data){
            root->left = insertBST(root->left,data);
        }
        else{
            root->right = insertBST(root->right,data);
        }
        return root;
    }

    Node *searchBST(Node*root,int data){
        if(root == NULL){
            return NULL;
        }
        if(root->data == data){
            return root;
        }
        if(data<root->data){
            return searchBST(root->left,data);
        }
        else{
            return searchBST(root->right,data);
        }
    }

    Node *deleteBST(Node *root,int data){
        if(root == NULL){
            return NULL;
        }
        if(data<root->data){
            root->left = deleteBST(root->left,data);
        }
        else if(data>root->data){
            root->right = deleteBST(root->right,data);
        }
        else{
            if(root->left == NULL){
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else{
                Node *temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deleteBST(root->right,temp->data);
            }
        }
        return root;
    }

    void inorder(Node *root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

int main(){
    BST bst;
    Node *root = NULL;
    cout<<"1. Insert in BST"<<endl;
    cout<<"2. Inorder Traversal of BST"<<endl;
    cout<<"3. Search in BST"<<endl;
    cout<<"4. Delete from BST"<<endl;
    cout<<"51. Exit"<<endl;

    int choice, val;
    do{
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter the value to be inserted: ";
                cin>>val;
                root = bst.insertBST(root,val);
                cout<<"Value inserted!:"<<endl;
                break;
            case 2:
                cout<<"The inorder traversal of the BST is: ";
                bst.inorder(root);
                break;
            case 3:
                cout<<"Enter the value to be searched: ";
                cin>>val;
                if(bst.searchBST(root,val) == NULL){
                    cout<<"Value not found!"<<endl;
                }
                else{
                    cout<<"Value found!"<<endl;
                }
                break;
            case 4:
                cout<<"Value to be deleted: ";
                cin>>val;
                bst.deleteBST(root,val);
                cout<<"Value deleted!"<<endl;

                break;
            case 5:
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice != 5);
    return 0;
}
