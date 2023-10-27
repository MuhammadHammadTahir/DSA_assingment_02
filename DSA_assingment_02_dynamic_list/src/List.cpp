#include "List.h"
#include <iostream>

template class List<int>;
template class List<float>;

using namespace std;

template <class T>
List<T>::List()
{
    list_elements= new T[10];
    size=0;
}

template <class T>
List<T>::~List()
{
    delete[] list_elements;
}

template <class T>
List<T>::List(const List& other)
{
    this->list_elements=new T[10];
    if(other.size!=0)
    {
        for(int i=0;i<other.size;i++)
        {
            this->list_elements[i]=other.list_elements[i];
            this->size++;
        }
    }
}

template <class T>
bool List<T>::empty() const
{
    if(size==0)
    {
        return true;
    }
    else{
        return false;
    }
}

template <class T>
int List<T>::length() const
{
    return size;
}

template <class T>
void List<T>::print() const
{
    cout<<"[";
    if(!empty())
    {
        cout<<list_elements[0];
        for(int i=1;i<size;i++)
        {
            cout<<", "<<list_elements[i];
        }
    }
    cout<<"]"<<endl;
}

template <class T>
void List<T>::delHead()
{
    if(!empty())
    {
        for(int i=0;i<size-1;i++)
        {
            list_elements[i]=list_elements[i+1];
        }
        size--;
    }
}

template <class T>
T List<T>::headElement() const
{
    if(!empty())
    {
    return list_elements[0];
    }
}

template <class T>
void List<T>::addHead(T newdata)
{
    if(size<10)
    {
    for(int i=size;i>=0;i--)
    {
        list_elements[i+1]=list_elements[i];
    }
    list_elements[0]=newdata;
    size++;
    }
}
