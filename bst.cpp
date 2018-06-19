#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
};

// returns a new node
node* new_node( int v ){
	node* n= new node;
	n->val= v;
	n->left= n->right= NULL;

	return n;
}

// insert a new node into tree
node* insert( node* root, int key ){
	if( root== NULL )
		return new_node( key );

	if( key < root->val )
		root->left= insert( root->left, key ); 

	else
		root->right= insert( root->right, key );

	return root;

}

// returns node with value key
node* search_node( node* root, int key ){
	if( root== NULL )
		return root;
	if( root->val== key )
		return root;

	if( key < root->val )
		return search_node( root->left, key );
	else
		return search_node( root->right, key );
}

// returns minimum value node
node* min_val_node( node* root ){

	if( root== NULL || root->left== NULL )
		return root;

	return min_val_node( root->left );
}

// returns maximum value node
node* max_val_node( node* root ){
	if( root== NULL || root->right== NULL )
		return root;

	return max_val_node( root->right );
}

// delete the node with value key
node* delete_node( node* root, int key ){

	if( root== NULL )
		return root;

	if( key < root->val )
		root->left= delete_node( root->left, key );
	else if( key > root->val )
		root->right= delete_node( root->right, key );
	else{

		if( root->left== NULL ){

			node* right= root->right;
			delete root;
			return right;
		
		}else if( root->right== NULL ){
		
			node* left= root->left;
			delete root;
			return left;
		
		}else{

			node* temp= min_val_node( root->right );
			root->val= temp->val;

			root->right= delete_node( root->right, temp->val );
		}


	}

	return root;

}


// inorder traversal
void inorder( node* root ){
	if( root== NULL )
		return;

	if( root->left )
		inorder( root->left );
	
	cout << root->val << ' ';
	
	if( root->right )
		inorder( root->right );
}

// preorder traversal
void preorder( node* root ){
	if( root== NULL )
		return;

	cout << root->val << ' ';

	if( root->left )
		preorder( root->left );

	if( root->right )
		preorder( root->right );
}

// postorder traversal
void postorder( node* root ){
	if( root== NULL )
		return;

	if( root->left )
		postorder( root->left );

	if( root->right )
		postorder( root->right );

	cout << root->val << ' ';
}

// return inorder successor of node with value 'key';
node* inorder_successor( node* root, int key ){
	node* curr= search_node( root, key );

	if( curr== NULL )
		return new_node( INT_MAX );

	if( curr->right ) 
		return min_val_node( curr->right );
	else{

		node* succ= NULL;
		node* pre= root;

		while( pre!= curr ){
			if( key < pre->val ){
				succ= pre;
				pre= pre->left;
			}else{
				pre= pre->right;
			}
		}

		if( succ ){
			return succ;
		}else{
			return new_node( INT_MAX );
		}

	}
}

// return inorder predecessor of node with value 'key'
node* inorder_predecessor( node* root, int key ){
	node* curr= search_node( root, key );

	if( curr== NULL )
		return new_node( INT_MIN );

	if( curr->left )
		return max_val_node( curr->left );
	else{

		node* pre= NULL;
		node* temp= root;

		while( temp!= curr ){
			if( key > temp->val ){
				pre= temp;
				temp= temp->right;
			}else{
				temp= temp->left;
			}
		}

		if( pre )
			return pre;
		else
			return new_node( INT_MIN );
	}
}


int main(){

	node* root= insert( root, 10 );
	root= insert( root, 7 );
	root= insert( root, 15 );
	root= insert( root, 12 );
	root= insert( root, 9 );
	root= insert( root, 13 );
	root= insert( root, 6 );
	root= insert( root, 16 );
	root= insert( root, 5 );

	inorder( root );
	cout << endl;

	cout << inorder_predecessor( root, 10 )->val << endl ;
	//cout << inorder_predecessor( root, 12 )->val;

}