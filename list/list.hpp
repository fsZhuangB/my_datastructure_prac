// 单向链表类
#include "ListNode.hpp"
#include <iostream>

template <class T>
class List {
    public:
    // 头尾哨兵节点
    //int _size;
    ListNode<T> * header;
    ListNode<T> * trailer;

    public:

    List();
    //~List();

    // 重载[]接口
    T& operator[] (Rank r) const
    {
        ListNode<T> * current = header->next;
        int count = 0;
        while (count != r)
        {
            current = current->next;
            count++;
        }
        return current->data;
    }

    Rank size() const
    {
        ListNode<T>* current = header->next;
        int count = 0;
        while (current != trailer)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    bool isEmpty() const
    {
        if (header->next != nullptr)
            return false;
        else
            return true;
    }

    ListNode<T>* first() const
    {
        return header->next;
    }
    ListNode<T>* last() const
    {
        ListNode<T>* current = header;
        ListNode<T>* firstNode;
        while (current != trailer)
        {
            firstNode = firstNode->next;
            current = current->next;
        }
        return firstNode;
    }
    void BuildOneTwoThree();

    void Iterator() const;

    // 删除位置p处的节点，并返回该节点的值
    T remove(Rank r);
    // T remove(T data);
};

template <typename T>
List<T>::List()
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->next = trailer;
    trailer->next = nullptr;
    //_size = 0;
}

template <typename T>
void List<T>::Iterator() const
{
    ListNode<T>* current = header->next;
    while (current != trailer)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void List<T>::BuildOneTwoThree()
{
    ListNode<T>* One;
    ListNode<T>* Two; 
    ListNode<T>* Three;

    One = new ListNode<T>;
    Two = new ListNode<T>;
    Three = new ListNode<T>;

    One->data = 1;
    this->header->next = One;
    One->next = this->trailer;

    Two->data = 2;
    One->next = Two;
    Two->next = this->trailer;

    Three->data = 3;
    Two->next = Three;
    Three->next = this->trailer;

    //return header;
}

template <typename T>
T List<T>::remove(Rank r)
{
    if (r == 0)
    {
        ListNode<T>* current = header->next;
        header->next = current->next;
        delete current;
    }
    else
    {
        // current节点指向首节点
        ListNode<T>* current = header->next->next;

        // 用作记录前一个节点
        ListNode<T>* record_node = header->next;

        // 用循环获取节点p的前一个节点
        while ((current->data != r) && (current != trailer))
        {
            current = current->next;
            record_node = record_node->next;
        }

        record_node->next = current->next;
        delete current;
    }

    return r;
}






