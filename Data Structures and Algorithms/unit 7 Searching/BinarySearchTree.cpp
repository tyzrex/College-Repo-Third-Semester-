#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertBST(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertBST(root->left, val);
    }

    else{
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorderTraverse(Node *root){
    if(root == NULL){
        return;
    }
    inorderTraverse(root->left);
    cout << root->data << " ";
    inorderTraverse(root->right);
}

void searchBST(Node *root, int key){
    if(root == NULL){
        cout << "Element not found!";
        return;
    }
    if(root->data == key){
        cout << "Element found!";
        return;
    }
    if(key < root->data){
        searchBST(root->left, key);
    }
    else{
        searchBST(root->right, key);
    }
}

int main(){
    Node *root = NULL;

    cout<<"1. Insert in BST"<<endl;
    cout<<"2. Inorder Traversal of BST"<<endl;
    cout<<"3. Search in BST"<<endl;
    cout<<"4. Exit"<<endl;

    int choice, val;
    do{
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter the value to be inserted: ";
                cin>>val;
                root = insertBST(root, val);
                break;
            case 2:
                cout<<"The inorder traversal of the BST is: ";
                inorderTraverse(root);
                break;
            case 3:
                cout<<"Enter the value to be searched: ";
                cin>>val;
                searchBST(root, val);
                break;
            case 4:
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice != 4);
    return 0;
}