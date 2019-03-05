#include "listNode.hpp"
#include <iostream>

template <typename T>
class List {

private:
    // 头尾哨兵节点
    ListNode<T>* header;
    ListNode<T>* trailer;

protected:
    void init();

public:
    // 默认构造函数
    List() { init(); };
    // 返回链表大小
    int size();
    // 重载[]操作符
    T& operator[] (Rank r) const;
    // 插入1、2、3三个节点
    void BuildOneTwoThree();

    // 输出节点
    void Iterator();
    
};

template <typename T>
void List<T>::init() 
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pre = nullptr;
    trailer->succ = nullptr;
    trailer->pre = header;
}

template <typename T>
int List<T>::size()
{
    ListNode<T>* current = header->next;
    int count = 0;
    while (current != trailer)
    {
        current = current->succ;
        count++;
    }
    return count;
}

template <typename T>
T& List<T>::operator[] (Rank r) const
{
    ListNode<T>* current = header->next;
    int count = 0;
    while (current != trailer && count != r)
    {
        current = current->next;
        count++;
    }
    return current->data;
}

template <typename T>
void List<T>::BuildOneTwoThree()
{
    ListNode<T>* one;
    ListNode<T>* two;
    ListNode<T>* three;

    one = new ListNode<T>;
    header->succ = one;
    one->pre = header;
    one->succ = trailer;
    trailer->pre = one;
    one->data = 1;

    two = new ListNode<T>;
    one->succ = two;
    two->pre = one;
    two->succ = trailer;
    trailer->pre = two;
    two->data = 2;

    three = new ListNode<T>;
    two->succ = three;
    three->pre = two;
    three->succ = trailer;
    trailer->pre = three;
    three->data = 3;

}

template <typename T>
void List<T>::Iterator()
{
    ListNode<T>* current = header->succ;
    while (current != trailer)
    {
        std::cout << current->data << " ";
        current = current->succ;
    }
    std::cout << std::endl;
}
