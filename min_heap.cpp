#include <bits/stdc++.h>
using namespace std;

// returns the parent of node 'id'
int parent( int id ){
	return (id-1)/2;
}

// return left child of node 'id'
int left( int id ){
	return 2*id + 1;
}

// return right child of node 'id'
int right( int id ){
	return 2*id + 2;
}

// maintains the min-heap property
void heapify_down( int a[], int n, int id ){

	int l= left( id );	
	int r= right( id );
	int mini= id;

	if( l < n && a[l] < a[mini] )
		mini= l;
	if( r < n && a[r] < a[mini] )
		mini= r;

	if( mini!= id ){
		swap( a[id], a[mini] );
		heapify_down( a, n, mini );
	}

}

void heapify_up( int a[], int n, int id ){
	while( id!= 0 ){
		int p= parent( id );
		if( a[p] > a[id] ){
			swap( a[p], a[id] );
			id= p;
		}else{
			return ;
		}
	}
}

// build heap of the array
void build_heap( int a[], int n ){
	for( int i= n/2; i>= 0; --i ){
		heapify_down( a, n, i );
	}
}


// insert item into heap
void insert( int a[], int &n, int val ){
	a[n]= val;
	int id= n;
	n++;
	heapify_up( a, n, id );
}

// decrease key in heap at index 'id' to 'new_key'
void decrease_key( int a[], int n, int id, int new_key ){
	a[id]= new_key;

	heapify_up( a, n, id );
}

// extract min from heap i.e. remove min element from heap
int extract_min( int a[], int &n ){
	int min= a[0];

	a[0]= a[n-1];
	n--;

	heapify_down( a, n, 0 );

	return min;
}

// delete key with index 'id' from heap
void delete_key( int a[], int &n, int id ){

	decrease_key( a, n, id, INT_MIN );
	extract_min( a, n );
}

// in decreasing order;
void heap_sort( int a[], int n ){
	
	build_heap( a, n );

	for( int i= n-1; i>= 0; --i ){
		swap( a[i], a[0] );
		heapify_down( a, i, 0 );
	}

}


// print the heap
void print( int a[], int n ){
	for( int i= 0; i< n; ++i )
		cout << a[i] << ' ';

	cout << endl;
}

int main(){

	int a[50]= { 10, 15, 14, 20, 8, 12, 16, 17 };
	int n= 8;

	build_heap( a, n );

	insert( a, n, 6 );

	print( a, n );

	heap_sort( a , n );

	print( a, n );
}