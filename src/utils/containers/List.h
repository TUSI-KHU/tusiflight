#ifndef LIST_H
#define LIST_H
#include<iostream>
using namespace std;

template<class T>
struct Node{
    Node *front;
    Node *next;
    T info;
    Node(const T &data) : info(data){}
};

template<class T>
class List{
public:
    List(){
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }

    ~List(){
        Node<T> *current = _head;
        while(current!=nullptr){
            Node<T> *temp = current;
            current = current->next;
            delete temp;
        }
    }

    inline bool IsEmpty(){
        if(_size==0) return true;
        else return false;
    }

    void push_back(T info){
        Node<T> *item = new Node<T>(info);
        item->next = nullptr;
        if(_head == nullptr){
            _head = item;
            _tail = item;
            item->front = nullptr;
        }
        else{
            item->front = _tail;
            _tail->next = item;
            _tail = item;
        }
        _size++;
    } 

    void push_front(T info){
        Node<T> *item = new Node<T>(info);
        item->front = nullptr;
        if(_head==nullptr){
            _head = item;
            _tail = item;
            item->next = nullptr;
        }
        else{
            _head->front = item;
            item->next = _head;
            _head = item;
        }
        _size++;
    }

    inline void pop_back(){
        if(IsEmpty()==true){
            //에러 메세지
            return;
        }
        if(_tail->front==nullptr){
            delete _tail;
            _head = nullptr;
            _tail = nullptr;
        }
        else{
            Node<T> *temp = _tail->front;
            delete _tail;
            _tail = temp;
            _tail->next = nullptr;
        }
        _size--;
    }

    inline void pop_front(){
        if(IsEmpty()==true){
            //에러 메세지
            return;
        }
        if(_head->next == nullptr){
            delete _head;
            _head = nullptr;
            _tail = nullptr;
        }
        else{
            Node<T> *temp = _head->next;
            delete _head;
            _head = temp;
            _head->front = nullptr;
        }
        _size--;
    }
    
    // 비어있을때 insert 함수 시도 시 에러
    void insert(int index, T info){
        if(index>=_size||0>index){
            // 에러 메세지
            return;
        }
        Node<T> *current = _head;
        for(int i = 0;i<index;i++){
            current = current->next;
        }
        // index가 0일때
        if(current==_head){
            push_front(info);
        }
        else if(current==_tail){
        	push_back(info);
		}
        else{
        	Node<T> *item = new Node<T>(info);
            item->next = current;
            item->front = current->front;
            current->front->next = item;
            current->front = item;
        }
        _size++;
    }

    void remove(int index){
        if(index>=_size||0>index){
            // 에러 메세지
            return;
        }
        Node<T> *current = _head;
        for(int i=0;i<index;i++){
            current = current->next;
        }
        // size가 1일때
        if(current->front==NULL&&current->next==NULL){
            pop_front();
        }
        // 맨 앞의 값 제거 할 때
        else if(current->front==NULL){
            pop_front();
        }
        //맨 뒤의 값 제거 할 때
        else if(current->next==NULL){
            pop_back();
        }
        else{
            current->front->next = current->next;
            current->next->front = current->front;
            delete current;
        }
        _size--;
    }

    int size(){
        return _size;
    }

    void clear(){
        for(int i=0;i<_size;i++) pop_front();
        _size = 0;
        _head = nullptr;
        _tail = nullptr;   
    }

    void print(){
        Node<T> *current = _head;
        while(current!=nullptr){
            cout<<(current->info)<<" ";
            current = current->next;
        }
        cout<<endl;
    }

    Node<T> *begin(){
        return &_head;
    }

    Node<T> *end(){
        return &_tail;
    }

    T & operator[](const int idx){
    	if(idx>=_size||0>idx){
    		cout<<"참조 할 수 없는 영역입니다.\n";
		}
		else{
			Node<T> *current = _head;
			for(int i=0;i<idx;i++){
				current = current->next;
			}
			return current->info;
		}
	}

    List<T> & operator=(const List<T> &ref){
        clear();
        Node<T> *current = ref._head;
        while(current!=nullptr){
            this->push_back(current->info);
            current = current->next;
        }
        return *this;
    }

private:
    Node<T> *_head;
    Node<T> *_tail;
    int _size;
};
#endif