typedef int Rank;
#define DEFAULT_CAPACITY 3 // 默认初始容量

template <class T>
class Vector {
    protected:
        Rank _size, int _capacity;
        T * _elem;  // 内置数组
    public:
        // 构造函数
            // 容量为c，规模为s，其中元素初始化为v
        Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
        {
            _elem = new T[_capacity = c];
            for (_size = 0; _size < s; _size++)
                _elem[_size] = v;
        }

        // 空间不足时扩容
        void expand();

        // 析构函数
        ~Vector() {delete [] _elem;}

        protected:
        Rank size() const {return _size;}
        bool empty() const {return !_size;}
};

template <class T>
void Vector<T>::expand()
{
    if (_size < _capacity)
        return;
    else
    {
        _capacity = std::max(_capacity, DEFAULT_CAPACITY);
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