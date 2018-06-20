#include <bits/stdc++.h>
using namespace std;

// parent of node 'id'
int parent( int id ){
	return ( id-1 )/2;
}

// left child of node 'id'
int left( int id ){
	return ( id*2 + 1 );
}

// right child of node 'id'
int right( int id ){
	return ( 2*id + 2 );
}

// to preserve the max heap property
void heapify_down( int a[], int n, int id ){

	int l= left( id );
	int r= right( id );
	int maxi= id;

	if( l < n && a[l] > a[maxi] )
		maxi= l;

	if( r < n && a[r] > a[maxi] )
		maxi= r;

	if( maxi!= id ){
		swap( a[id], a[maxi] );
		heapify_down( a, n, maxi );
	}

}

void heapify_up( int a[], int n, int id ){
	while( id!= 0 && a[parent(id)] < a[id] ){
		//cout << id << ' ' << parent( id ) << endl;
		swap( a[id], a[parent(id)] );
		id= parent( id );
	}
}

// build heap out of an array of size 'n';
void build_heap( int a[], int n ){
	for( int i= n/2; i>= 0; --i ){
		heapify_down( a, n, i );
	}
}

// insert element to heap
void insert_key( int a[], int &n, int key ){
	a[n]= key;
	n++;
	heapify_up( a, n, n-1 );
}

// increase key of element at index 'id' to new_key
void increase_key( int a[], int n, int id, int new_key ){
	a[id]= new_key;
	heapify_up( a, n, id );
}

int extract_max( int a[], int &n ){
	int maxi= a[0];

	a[0]= a[n-1];
	n--;
	
	heapify_down( a, n, 0 );
	
	return maxi;
}

void delete_key( int a[], int &n, int id ){
	
	increase_key( a, n, id, INT_MAX );
	extract_max( a, n );
}

// sort the heap in increasing order
void heap_sort( int a[], int n ){

	build_heap( a, n );

	for( int i= n-1; i>= 0; --i ){
		swap( a[0], a[i] );
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

	print( a, n );

	insert_key( a, n, 19 );

	print( a, n );

	heap_sort( a, n );

	print( a, n );
}