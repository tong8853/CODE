#include "SeqStack.h"

template <class DataType>
SeqStack<DataType>::SeqStack(){
    top = -1;
}

template <class DataType>
void SeqStack<DataType>::Push(DataType x){
    if(top == StackSize - 1) throw "上溢";
    top++;
    data[top] = x;
}

template <class DataType>
DataType SeqStack<DataType>::Pop(){
    if(top == -1) throw "下溢";
    DataType x = data[top];
    top--;
    return x;
}

template <class DataType>
DataType SeqStack<DataType>::GetTop(){
    if(top == -1) throw "栈空";
    return data[top];
}

template <class DataType>
int SeqStack<DataType>::Empty(){
    if(top == -1) return 1;
    else return 0;
}