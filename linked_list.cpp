#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
}* head;

node* new_node( int v ){

    node* n= new node;
    n->data= v;
    n->next= NULL;

    return n;
}

// add a node to the end
void add( node** head, int v ){

    node* n= new_node( v );

    if( *head== NULL ){
        *head= n;
    }else{

        node* curr= *head;

        while( curr->next!= NULL )
            curr= curr->next;

        curr->next= n;

    }
}

// find a node
node* locate( node* head, int v ){

    while( head->next!= NULL ){
        if( head->data== v )
            return head;
        head= head->next;
    }

    if( head->data== v )
        return head;

    return NULL;
}

// insert node before 'before'
void insert( node** head, int before, int v ){

    node* here= locate( *head, before );

    if( here== NULL )
        return;

    node* n= new_node( v );

    if( here== *head ){
        n->next= *head;
        *head= n;
    }else{

        node* curr= *head;

        while( curr->next!= here ){
            curr= curr->next;
        }

        n->next= curr->next;
        curr->next= n;
    }
}

// remove node with data 'v'
void eliminate( node** head, int v ){

    node* it= locate( *head, v );

    if( it== NULL )
        return ;
    if( it== *head ){
        node* x= *head;
        *head= (x)->next ;
        delete x;
        return;
    }


    node* curr= *head;

    while( curr->next!= it ){
        curr= curr->next;
    }

    if( curr->next->next== NULL ){
        curr->next== NULL;
    }else{
        curr->next= curr->next->next;
    }

    delete it;
}

// reverse the linked list
void turn( node** head ){

    if( *head== NULL || (*head)->next== NULL )
        return;

    node* prev= NULL;
    node* curr= *head;
    node* forw;

    while( curr!= NULL ){

        forw= curr->next;
        curr->next= prev;
        prev= curr;
        curr= forw;
    }

    *head= prev;
}

// find the cycle in the linked list

bool is_cyclic( node* head ){

    if( head->next== NULL )
        return false;

    node* slow= head;
    node* fast= slow->next;

    while( fast!= NULL && slow!= NULL && fast->next!= NULL ){
        fast= fast->next->next;
        slow= slow->next;

        if( fast== slow )
            return true;
    }

    return false;
}

// find middle element of the list
node* middle( node* head ){

    node* slow= head;
    node* fast= slow->next;

    while( fast!= NULL && fast->next!= NULL ){
        slow= slow->next;
        fast= fast->next->next;
    }

    return slow;
}

// delete list
void delete_list( node** head ){

    if( (*head)== NULL )
        return;

    node* curr= (*head)->next;

    while( curr!= NULL ){
        node* n= curr;
        curr= curr->next;

        delete n;
    }

    *head= NULL;
}

// remove duplicates from list
void remove_duplicates( node* head ){

    map< int, int > m;
    node* curr= head->next;
    node* prev= head;

    m[head->data]++;

    while( curr!= NULL ){

        if( m[curr->data] > 0 ){
            node* n= curr;
            prev->next= curr->next;
            curr= curr->next;

            delete n;
        }else{

            m[curr->data]++;
            prev= curr;
            curr= curr->next;
        }

    }

}

void print( node* head ){

    if( head== NULL )
        return;

    while( head->next!= NULL ){
        cout << head->data << ' ' ;
        head= head->next;
    }
    cout << head->data << endl;
}

int main(){

    add( &head, 1 );
    add( &head, 2 );
    add( &head, 1 );
    add( &head, 3 );
    add( &head, 2 );
    add( &head, 1 );
    add( &head, 3 );
    add( &head, 8 );

    print( head );
}