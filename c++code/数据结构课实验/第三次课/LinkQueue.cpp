#include "LinkQueue.h"

template <class Datatype>
LinkQueue<Datatype>::LinkQueue(){
    Node<Datatype> *s = new Node<Datatype>;
    s->next = NULL;
    front = rear = s;
}

template <class Datatype>
LinkQueue<Datatype>::~LinkQueue(){
    Node<Datatype> *p;
    while(front != NULL){
        p = front->next;
        delete front;
        front = p;
    }
}

template <class Datatype>
void LinkQueue<Datatype>::EnQueue(Datatype x){
    Node<Datatype> *s = new Node<Datatype>;
    s->data = x;
    s->next = NULL;
    rear->next = s;
    rear = s;
}

template <class Datatype>
Datatype LinkQueue<Datatype>::DeQueue(){
    if(rear == front) throw "下溢";
    Node<Datatype> *p = front->next;
    Datatype x = p->data;
    front->next = p->next;
    if(p->next == NULL) rear = front;
    delete p;
    return x;
}

template <class Datatype>
Datatype LinkQueue<Datatype>::GetQueue(){
    if(front == rear) throw "队列为空";
    return front->next->data;
}

template <class Datatype>
int LinkQueue<Datatype>::Empty(){
    if(front == rear) return 1;
    else return 0;
}