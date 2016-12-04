#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left, *right;
}*root;

node* new_node( int v ){
    node* n= new node;
    n->data= v;
    n->left= n->right= NULL;

    return n;
}

// insert a node in tree
node* insert( node* root, int v ){

    node* n= new_node( v );

    if( root== NULL )
        return n;
    else if( v < root->data ){
        root->left= insert( root->left, v );
    }else{
        root->right= insert( root->right, v );
    }

    return root;
}

// recursive method locate a node
node* locate( node* root, int v ){

    if( root == NULL )
        return root;

     if( root->data == v )
            return  root;

    if( v < root->data )
        return locate( root->left, v );
    else
        return locate( root->right, v );
}

//iterative method to locate a node
node* locate_iter( node* root, int v ){

    while( root!= NULL ){

        if( v == root->data )
            return root;
        else if( v < root->data )
            root= root->left;
        else
            root= root->right;
    }

    return root;
}

//recursive method to find minimum
node* minimum( node* root ){
    if( root->left )
        return minimum( root->left );
    else
        return root;
}

//recursive method to find maximum
node* maximum( node* root ){
    if( root->right )
        return minimum( root->right );
    else
        return root;
}

//iterative method to find minimum
node* minimum_iter( node* root ){

    while( root->left )
        root= root->left;

    return root;
}

//iterative method to find maximum
node* maximum_iter( node* root ){

    while( root->right )
        root= root->right;

    return root;
}

void inorder( node* root ){

    if( root!= NULL ){

        inorder( root->left );
        cout << root->data << ' ';
        inorder( root->right );

    }
}

void preorder( node* root ){
    if( root!= NULL ){

        cout << root->data << ' ';
        preorder( root->left );
        preorder( root->right );

    }
}

void postorder( node* root ){

    if( root!= NULL ){

        postorder( root->right );
        postorder( root->left );
        cout << root->data << ' ';
    }

}

int main(){

    root= insert( root, 50 );
    root= insert( root, 70 );
    root= insert( root, 30 );
    root= insert( root, 40 );
    root= insert( root, 60 );
    root= insert( root, 20 );
    root= insert( root, 25 );
    root= insert( root, 15 );
    root= insert( root, 65 );
    root= insert( root, 60 );
    root= insert( root, 80 );
    root= insert( root, 55 );

}
