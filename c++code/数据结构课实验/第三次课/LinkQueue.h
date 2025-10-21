#pragma once

template <class DataType>
struct Node{
    DataType data;
    Node<DataType> *next;
};

template <class DataType>
class LinkQueue{
    public:
        LinkQueue();
        ~LinkQueue();
        void EnQueue(DataType x);
        DataType DeQueue();
        DataType GetQueue();
        int Empty();
    private:
        Node<DataType> *front, *rear;
};