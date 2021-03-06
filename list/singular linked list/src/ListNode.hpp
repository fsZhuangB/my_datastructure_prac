// 单向链表节点类
typedef int Rank;

template <typename T>
class ListNode {
    public:  // 在此不进行进一步的封装
    T data;
    ListNode<T> * next;

    ListNode() {} 
    ListNode(T e, ListNode<T>* n = nullptr)
    : data(e), next(n) { } // 默认构造器
};

