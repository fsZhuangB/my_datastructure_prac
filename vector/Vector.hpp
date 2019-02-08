typedef Rank int
#define DEFAULT_CAPACITY 3 // 默认初始容量
template <class T>
class Vector {
    protected:
        Rank _size, int _capacity;
        T * _elem;  // 内置数组

};