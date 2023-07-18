#ifndef STACK_H
#define STACK_H


template<class T>
class Stack{
public:
    Stack(int max_size){
        _size = 0;
        _max_size = max_size;
        _array = new T*[_max_size];
    }

    ~Stack(){
        for(int i=0;i<_size;i++){
            delete _array[i];
        }
    }

    int size(){
        return _size;
    }

    void clear(){
        for(int i=0;i<_size;i++){
            delete _array[i];
        }
        _size = 0;
    }

    inline bool IsEmpty(){
        return _size==0;
    }

    inline bool IsFull(){
        return _size == _max_size;
    }

    void push(T info){
        if(IsFull()) return;
        _array[_size] = new T(info);
        _size++;
    }

    void pop(){
        if(IsEmpty()) return;
        delete _array[_size-1];
        _size--;
    }
    
    T &top(){
        if(IsEmpty()==false){
            return *(_array[_size-1]);
        }
    }

    Stack<T> & operator=(const Stack<T> &ref){
        clear();
        for(int i=0;i<ref._size;i++){
            push(*(ref._array[i]));
        }
        return *this;
    }

private:
    T **_array;
    int _size;
    int _max_size;
};

#endif