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
    ~List();

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

    // 在秩为r的地方插入节点
    ListNode<T>* insert(Rank r, T data);

    // 找前一个节点的函数
    ListNode<T>* findPrevious(Rank r);
    // 链表查找接口
    Rank find(T nodeData);
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
List<T>::~List()
{
   // ListNode<T>* current = header->next;
    ListNode<T>* current = header;

    while (current != trailer)
    {
        ListNode<T>* temp = current;
        current = current->next;
        delete temp;
    }
    delete trailer;
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

//  略繁琐，应思考并重写
template <typename T>
T List<T>::remove(Rank r)
{
    if (r >= this->size())
    {
        std::cerr << "wrong rank!\n";
        return -1;
    }
    else {
        if (r == 0)
        {
            ListNode<T>* current = header->next;
            header->next = current->next;
            delete current;
        }
        else
        {
            // 计数器，记录第n个节点
            int count = 0;
        // current节点指向首节点
            ListNode<T>* current = header->next;

            // 用作记录前一个节点
            ListNode<T>* record_node = header;

            // 用循环获取节点p的前一个节点
            while ((count != r) && (current != trailer))
            {
                current = current->next;
                record_node = record_node->next;
                count++;
            }

            record_node->next = current->next;
            delete current;
    }

    }
    return r;
}

template <typename T>
ListNode<T>* List<T>::insert(Rank r, T data)
{
    ListNode<T>* current = header->next;
    ListNode<T>* record = header;
    int count = 0;
    while (count != r && current != trailer)
    {
        current = current->next;
        record = record->next;
        count++;     
    }

    ListNode<T>* p = new ListNode<T>;
    record->next = p;
    p->data = data;
    p->next = current;

    return p;
}

template <typename T> 
Rank List<T>::find(T nodeData)
{
    ListNode<T>* current = header->next;
    int count = 0;
    while (current != trailer)
    {
        if (current->data == nodeData)
        {
            return count;
            break;
        }
        else
        {
            current = current->next;
            count++;
        }
    }

    return -1;
}

template <typename T>
ListNode<T>* List<T>::findPrevious(Rank r)
{
    ListNode<T>* current = header->next;
    ListNode<T>* previousNode = header;
    int count = 0;

    while (current != trailer && count != r)
    {
        current = current->next;
        previousNode = previousNode->next;
        count++;
    }

    return previousNode;

}

