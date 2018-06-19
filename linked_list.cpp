#include <bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node* next;
};

// create a new node with value v
node* new_node( int v ){
	node* n= new node;
	n->val= v;
	n->next= NULL;

	return n;
}

// return length of linked list starting from head;
int length( node* head ){
	int n= 0;

	while( head!= NULL ){
		n++;
		head= head->next;
	}

	return n;
}

// add node at the start
node* push_start( node* head, int v ){
	node* n= new_node( v );
	n->next= head;

	return n;
}

// add node at the end
node* push_end( node* head, int v ){
	if( head== NULL ){
		return new_node( v );
	}

	node* curr= head;

	while( curr->next!= NULL ){
		curr= curr->next;
	}

	curr->next= new_node( v );

	return head;
}

// print the list
void print( node* head ){

	while( head!= NULL ){
		cout << head->val << ' ' ;
		head= head->next;
	}

	cout << endl;

}

// insert node after nth node
node* insert_node( node* head, int n, int v ){
	node* curr= head;
	node* nn= new_node( v );

	while( --n && curr ){
		curr= curr->next;
	}

	if( curr== NULL )
		return head;

	nn->next= curr->next;
	curr->next= nn;

	return head;
}

//  removes head of the list
node* pop_start( node* head ){
	if( head== NULL )
		return head;
	node* curr= head;
	head= head->next;

	delete curr;

	return head;
}

// removes the last element of list
node* pop_end( node* head ){

	if( head== NULL )
		return head;

	if( head->next== NULL ){
		return pop_start( head );
	}

	node* curr= head;

	while( curr->next->next!= NULL ){
		curr= curr->next;
	}

	node* nn= curr->next;
	curr->next= NULL;

	delete nn;

	return head;
}

// removes all the nodes with value 'k'
node* remove( node* head, int k ){
	if( head== NULL )
		return head;

	node* dummy= new_node( INT_MAX );
	dummy->next= head;

	node* curr= dummy;

	while( curr->next ){
		if( curr->next->val== k ){
			node* to_delete= curr->next;
			curr->next= curr->next->next;
		}else{
			curr= curr->next;
		}
	}

	return dummy->next;
}

//  returns middle node of the list
node* middle( node* head ){
	node* fast= head;
	node* slow= head;

	while( fast && fast->next!= NULL ){
		fast= fast->next->next;
		slow= slow->next;
	}

	return slow;
}


// returns nth node from end
node* nth_from_end( node* head, int n ){
	node* fwd= head;
	node* bwd= head;

	for( int i= 0; i< n && fwd!= NULL; ++i ){
		fwd= fwd->next;
	}

	if( fwd== NULL )
		return fwd;

	while( fwd ){
		fwd= fwd->next;
		bwd= bwd->next;
	}

	return bwd;
}

// returns node where loop starts
node* detect_loop( node* head ){
	node* fast, *slow;

	fast= head; 
	slow= head;

	while( slow && fast && fast->next ){
		slow= slow->next;
		fast= fast->next->next;

		cout << slow->val << ' ' << fast->val << endl;

		if( slow== fast ){
			return slow;
		}
	}

	return NULL;
}

int main(){

	node* head;

	head= push_end( head, 1 );
	head= push_end( head, 2 );
	head= push_end( head, 3 );
	head= push_end( head, 4 );
	head= push_end( head, 5 );

	print( head );
}