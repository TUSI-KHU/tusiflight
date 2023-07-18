#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template<class T, bool (*_cmp)(T,T)> 
class PQ{
public:
    PQ(int max_size){
    	_size = 0;
        _max_size = max_size;
    	_tree = new T *[_max_size];
	}

    ~PQ(){
        for(int i=0;i<_size;i++){
            delete _tree[i];
        }
        delete[] _tree;
    }

    inline bool IsEmpty(){
        return _size==0;
    }

    inline bool IsFull(){
        return _size==_max_size;
    }

    // 포인터 에러 없는지 확인하기
    T &top(){
        if(IsEmpty()){
            // 에러 코드
        }
        else{
            return *(_tree[0]);
        }
    }

    void push(T info){
        if(IsFull()) return;
        _tree[_size] = new T(info);
        _HeapUp(_size);
        _size++;
    }
    
    void pop(){
        if(IsEmpty()) return;
        delete _tree[0];
        _tree[0] = _tree[_size-1]; 
        _size--;
        _HeapDown(0);
    }

    int size(){
        return _size;
    }

    void clear(){
        for(int i=0;i<_size;i++){
            delete _tree[i];
        }
        _size = 0;
    }

    PQ<T,_cmp> & operator=(const PQ<T,_cmp> &ref){
        clear();
        for(int i=0;i<ref._size;i++){
            push(*(ref._tree[i]));
        }
        return *this;
    }
private:
    int _size;
    int _max_size;
	T **_tree;
    void _HeapDown(int idx){
        int left = idx*2;
        int right = left+1;

        if(left<=_size-1){
            int priority_value; // 왼쪽과 오른쪽 자식 노드 중 우선순위가 더 높은 노드의 인덱스
            if(left==_size-1){ 
                priority_value = left;
            }
            else{
                if(_cmp(*(_tree[left]), *(_tree[right]))==true) priority_value = left;
                else priority_value = right;
            }

            if(_cmp(*(_tree[priority_value]), *(_tree[idx]))==true){
                T *temp = _tree[priority_value];
                _tree[priority_value] = _tree[idx];
                _tree[idx] = temp;
                _HeapDown(priority_value);
            }
        }
    }

    void _HeapUp(int idx){
        if(idx!=0){
            int parent = idx/2;
            if(_cmp(*(_tree[idx]), *(_tree[parent]))==true){
                T *temp = _tree[parent];
                _tree[parent] = _tree[idx];
                _tree[idx] = temp;
                _HeapUp(parent);
            }
        }
    }
};



#endif