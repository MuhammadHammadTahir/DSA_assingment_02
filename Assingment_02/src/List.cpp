#include<iostream>
#include<string>
#include "List.h"

template class List<int>;
template class List<float>;

using namespace std;

template <class T>
List<T>::List()
{
    head=NULL;                          //set the head element
}

template <class T>
List<T>::~List()
{
    /*if(!empty())
    {
    Nodeptr curr=head;
    Nodeptr clear_l=head;
    while(curr!=NULL)
    {
        clear_l=curr;
        delete clear_l;         //delete all the list elements
        curr=curr->next;
    }
    }*/
    while(head!=NULL)
    {
        this->delHead();
    }
    delete head;                //delete the head pointer
}

template <class T>
List<T>::List(const List& other)
{
    head = NULL;
    Node<T>* cur = other.head;
    while(cur != NULL)
    {
    Node<T>* new_node=new Node<T>;
    new_node->data=cur->data;
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
    Node<T>* curr_2 = head;
     while(curr_2->next!=NULL)
     {
         curr_2=curr_2->next;
     }
     curr_2->next=new_node;
     new_node->next=NULL;
    }
    cur = cur->next;
    }
}

template <class T>
bool List<T>::empty() const
{
    if(head==NULL)
        return true;
    else
        return false;
}

template <class T>
T List<T>::headElement() const
{
    if(empty())
    {
        cout<<endl<<"List R empty"<<endl;
    }
    else
        {
            return head->data;
        }
}

template <class T>
void List<T>::addHead(T newdata)
{
    Node<T>* new_node=new Node<T>;
    new_node->data=newdata;
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
}

template <class T>
void List<T>::delHead()
{
    if(empty())
    {
        return ;
    }
    Node<T>* curr;
    curr=head;
    head=head->next;
    delete curr;
}

template <class T>
int List<T>::length() const
{
    int count=0;
    Node<T>* curr;
    curr=head;
    while(curr!=NULL)
    {
        count++;
        curr=curr->next;

    }
    return count;
}

template <class T>
void List<T>::print() const
{
    Node<T>* curr=head;
    cout<<"[";
    if(!empty()){
    cout << curr->data;
    curr = curr->next;
    }
    while(curr != NULL){
        cout << ", " << curr->data;
        curr = curr -> next;
    }
    cout << "]" << endl;
}














