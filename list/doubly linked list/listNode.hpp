typedef int Rank;

template <typename T>
class ListNode
{
    T data;
    // 双向链表指针
    ListNode<T>* pre;  
    ListNode<T>* succ;

    ListNode() {};
    ListNode(T e, ListNode<T>* p = nullptr, ListNode<T>* s = nullptr)
    : data(e), pre(p), succ(s) { }
};