typedef int Rank;
#define DEFAULT_CAPACITY 3 // 默认初始容量

template <class T>
class Vector {
    protected:
        Rank _size;
        int _capacity;
        T * _elem;  // 内置数组
    public:
        // 构造函数
        //Vector();
            // 容量为c，规模为s，其中元素初始化为v
        Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
        {
            _elem = new T[_capacity = c];
            for (_size = 0; _size < s; _size++)
                _elem[_size] = v;
        }

        // 数组复制构造函数
        Vector(T const* A, Rank n)
        {
            copyFrom(A, 0, n);
        }

        // 析构函数
        ~Vector() {delete [] _elem;}

        T& operator[] (Rank r)
        {
            return _elem[r];
        }
        protected:
         // 空间不足时扩容
        void expand();
        Rank size() const {return _size;}
        bool empty() const {return !_size;}
        void copyFrom(T const* A, Rank lo, Rank hi); // 复制数组区间[lo, hi)
};

template <class T>
void Vector<T>::expand()
{
    if (_size < _capacity)
        return;
    else
    {
        _capacity = max(_capacity, DEFAULT_CAPACITY);
        _capacity = 2 * _capacity;
        T * oldElem = _elem;
        _elem = new T[_capacity]; // 分配新的空间
        for (int i = 0; i < _size; i++)
        {
            _elem[i] = oldElem[i];
        }

        delete [] oldElem;  // 释放原空间
    }
}

template <class T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
    _capacity = (hi - lo) * 2;
    _elem = new T[_capacity];
    while (lo < hi)
    {
        _elem[_size++] = _elem[lo++];
    }
}