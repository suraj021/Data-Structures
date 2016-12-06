#include <bits/stdc++.h>
using namespace std;

void min_heapify( int a[], int n, int i ){

    int left= 2*i;
    int right= left+1;
    int mini;

    if( left < n && a[left] < a[i] ){
        mini= left;
    }else{
        mini= i;
    }
    if( right < n && a[right] < a[mini] ){
        mini= right;
    }

    if( mini!= i ){
        swap( a[i], a[mini] );
        min_heapify( a, n, mini );
    }

}

void build_heap( int a[], int n ){

    for( int i= n/2; i > 0; --i )
        min_heapify( a, n, i );

}

void decrease_key( int a[], int i, int x ){

    if( a[i] < x )
        return;

    a[i]= x;

    int p= i/2;

    while( i > 1 && a[p] > a[i] ){
        swap( a[i], a[p] );
        i= p;
        p= i/2;
    }
}

void heap_sort( int a[], int n ){

    for( int i= n-1; i> 1 ; --i ){
        swap( a[i], a[1] );
        n= n-1;
        min_heapify( a, n, 1 );
    }
}

void push( int a[], int n, int i, int x ){

    a[i]= x;

    int p= i/2;

    while( i > 1 && a[p] > a[i] ){
        swap( a[i], a[p] );
        i= p;
        p= i/2;
    }

}

int extract_min( int a[], int n ){

    int mini= a[1];
    a[1]= a[n-1];

    min_heapify( a, n-1, 1 );

    return mini;
}

void remove_key( int a[], int n, int i ){

    a[i]= a[n-1];

    int p= i/2;

    if( i== 1 || a[p] < a[i] ){
        while( i > 1 && a[p] < a[i] ){
            swap( a[i], a[p] );
            i= p;
            p= i/2;
        }
    }else{
        min_heapify( a, n-1, i );
    }
}

int main(){

    int a[100]= { 0, 50, 60, 10, 20, 40 ,30 , 70, 90, 80 };
    int n= 10;

    build_heap( a, n );

    for( int i= 0; i< n; ++i )
        cout << a[i] << ' ';

    cout << endl;

    //cout << extract_min( a, n ) << endl;



}
