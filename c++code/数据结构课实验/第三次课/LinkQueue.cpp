#include "LinkQueue.h"

template <class Datatype>
LinkQueue<Datatype>::LinkQueue(){
    Node<DataType> *s = NULL;
    s = new Node<DataType>;
    s->next = NULL;
    front = rear = s;
}

template <class Datatype>
LinkQueue<Datatype>::~LinkQueue(){
    Node<DataType> *s = NULL;
    while(front != NILL){
        p = front->next;
        delete front;
        front = p;
    }
}

template <class Datatype>
void LinkQueue<Datatype>::EnQueue(Datatype x){
    Node<DataType> *s = NULL;
    s = new Node<DataType>;
    s->data = x;
    s->next = NULL;
    rear->next = s;
    rear  = s;
}

template <class Datatype>
Datatype LinkQueue<Datatype>::DeQueue(){
    Node<DataType> *s = NULL;
    int x;
    if(rear == front) throw "下溢"
    p = front->next;
    x = p->data;
    front->next = p->next;
    if(p -> next == NULL) rear = front;
    delete p;
    return x;
}

template <class Datatype>
Datatype LinkQueue<Datatype>::GetQueue(){
    if(front != rear) return front->next->data;
}

template <class Datatype>
int LinkQueue<Datatype>::Empty(){
    if(front == rear) return 1;
    else return 0;
}