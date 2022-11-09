#pragma once
// Name: Prof Q, Ba Dieu
// Date: 11-3-2021
// Description: binary tree node for growing a tree
#include <iostream>
#include <string>
#include <queue>
using namespace std;

template <class Item>
class binary_tree_node
{
private:
    Item data;
    binary_tree_node* left;
    binary_tree_node* right;

public:

    //constructor
    binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
    {
        data = init_data;
        left = init_left;
        right = init_right;
    }

    
    Item& getData()
    {
        return data;
    }

    binary_tree_node*& getLeft()
    {
        return left;
    }

    binary_tree_node*& getRight()
    {
        return right;
    }

    void setData(const Item& new_data)
    {
        data = new_data;
    }

    void setLeft(binary_tree_node* new_left)
    {
        left = new_left;
    }

    void setRight(binary_tree_node* new_right)
    {
        right = new_right;
    }

    const Item& getData() const
    {
        return data;
    }
    
    const binary_tree_node* getLeft() const
    {
        return left;
    }

    const binary_tree_node* getRight() const
    {
        return right;
    }
  
    bool isLeaf() const
    {
        return (left == NULL && right == NULL);
    }


    binary_tree_node* CreateNode(Item data)
    {
        binary_tree_node* newNode = new binary_tree_node();
        newNode->setData(data);
        newNode->setLeft(NULL);
        newNode->setRight(NULL);
        return newNode;
    }
    
    binary_tree_node* InsertNode(binary_tree_node* root, Item data)
    {
        // If the tree is empty, assign new node address to root
        if (root == NULL) {
            root = CreateNode(data);
            return root;
        }

        queue<binary_tree_node*> q;
        q.push(root);

        while (!q.empty()) {
            binary_tree_node* temp = q.front();
            q.pop();

            if (temp->getLeft() != NULL)
                q.push(temp->getLeft());
            else {
                temp->setLeft(CreateNode(data));
                return root;
            }

            if (temp->getRight() != NULL)
                q.push(temp->getRight());
            else {
                temp->setRight(CreateNode(data));
                return root;
            }
        }
    }
    //
};

template<class Item>
void delete_tree(binary_tree_node<Item>* leaf) // Recursive
{
    if (leaf == NULL)
        return;

    /* first delete both subtrees */
    delete_tree(leaf->getLeft());
    delete_tree(leaf->getRight());

    /* then delete the node */
    cout << "\n\t\tDeleting: " << leaf->getData();
    delete leaf;

}

template<class Item>
void print_tree(const string& prefix, const binary_tree_node<Item>* node, bool isLeft, bool root, bool last)
{
    if (node != NULL)
    {
        cout << prefix;
        if (!root)
        {
            if (isLeft)
            {
                if (node->getLeft() == NULL && node->getRight() == NULL)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            else
            {
                if (last)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            cout << " " << node->getData() << '\n';
        }
        else
            cout << "    " << node->getData() << '\n';


        // enter the next tree level - left and right branch
        string s = "    ";
        s[0] = char(179);
        print_tree(prefix + (isLeft ? s : "    "), node->getLeft(), true, false, false);
        print_tree(prefix + (isLeft ? s : "    "), node->getRight(), false, false,true);
    }
}

// Precondition: node_ptr is a pointer to a node in a binary tree (or
// node_ptr may be NULL to indicate the empty tree).
// Postcondition: If node_ptr is non-NULL, then the data of *node_ptr and
// all its descendants have been written to cout with the << operator, using 
// a pre-order traversal.
// Library facilities used: cstdlib, iostream
template <class Item>
void preorder_print(const binary_tree_node<Item>* node_ptr)
{
    if (node_ptr != NULL)
    {
        cout << node_ptr->getData() << endl;
        preorder_print(node_ptr->getLeft());
        preorder_print(node_ptr->getRight());
    }
}

// Precondition: node_ptr is a pointer to a node in a binary tree (or
// node_ptr may be NULL to indicate the empty tree).
// Postcondition: If node_ptr is non-NULL, then the data of *node_ptr and
// all its descendants have been written to cout with the << operator, using
// an in-order traversal.
// Library facilities used: cstdlib, iostream
template <class Item>
void inorder_print(const binary_tree_node<Item>* node_ptr)
{
    if (node_ptr != NULL)
    {
        preorder_print(node_ptr->getLeft());
        cout << node_ptr->getData() << endl;
        preorder_print(node_ptr->getRight());
    }
}

// Precondition: node_ptr is a pointer to a node in a binary tree (or
// node_ptr may be NULL to indicate the empty tree).
// Postcondition: If node_ptr is non-NULL, then the data of *node_ptr and
// all its descendants have been written to cout with the << operator, using
// an in-order traversal.
// Library facilities used: cstdlib, iostream
template <class Item>
void postorder_print(const binary_tree_node<Item>* node_ptr)
{
    if (node_ptr != NULL)
    {
        preorder_print(node_ptr->getLeft());
        preorder_print(node_ptr->getRight());
        cout << node_ptr->getData() << endl;
    }
}

template <class Item>
bool binary_search(const binary_tree_node<Item>* node_ptr, Item s_item){
        // This checks first root node
        if (node_ptr != NULL) {
            if (node_ptr->getData() != s_item) {
                if (binary_search(node_ptr->getLeft(), s_item)) {
                    return true;
                }
            }
            else {
                return true;
            }
            if (binary_search(node_ptr->getRight(), s_item)) {
                return true;
                }
            }
            else {
        }
        return false;
}

template <class Item>
int tree_count(const binary_tree_node<Item>* node_ptr,int & i){
    if (node_ptr != NULL)
    {
        i++;
        tree_count(node_ptr->getLeft(),i);
        tree_count(node_ptr->getRight(),i);
    }
    return i;
}
