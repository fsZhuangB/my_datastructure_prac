// list
#include "ListNode.hpp"
#include <iostream>

template <class T>
class List {

    private:
    // 头尾哨兵节点
    ListNode * header;
    ListNode * trailer;

    public:
    List();
    ~List();

    // 重载[]接口
    T& operator[] (Rank r) const;

    Rank size() const;
    bool empty() const;

    ListNode * first() const;
    ListNode * last() const;
    




};