#include "List.h"
#include "List_impl.cpp"
#include <iostream>

using namespace std;

template <class T>
List<T>::List()
{
    size=0;
}

template <class T>
List<T>::~List()
{
    //destructor
}

template <class T>
List<T>::List(const List& other)
{

    if (!other.empty())
    {
        for (int i=0; i<other.size; i++)
        {
        this->head[i]=other.head[i];
        this->size++;
        }
    }
}

template <class T>
void List<T>::addHead(T newdata)
{
    if (size<10000) {
    for (int i=size; i>=0;i--) head[i+1]=head[i];
    head[0]=newdata;
    size++;
}
}

template <class T>
T List<T>::headElement() const
{
    if(!empty())
    {
        return head[0];
    }

}

template <class T>
void List<T>::delHead()
{
    for(int i=0;i<size-1;i++)
    {
        head[i]=head[i+1];
    }
    size--;
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
        cout<<head[0];
        for(int i=1;i<size;i++)
        {
            cout<<", "<<head[i];
        }

    }
    cout<<"]"<<endl;
}
