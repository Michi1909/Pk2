#ifndef _Stach_H_INCLUDED
#define _Stach_H_INCLUDED


#include<iostream>
#include"empty_stack_exception.h"
using namespace std ;
namespace std_Stack{
template<typename T> class Stack{
private : 
struct Element{
    T key ; 
    Element * next ; 
    Element(T key , Element *next):key(key),next(next){} 
    ~Element(){cout << "Destruktor" << endl;}
    };
typedef struct  Element* element ; 
element top ; 
public:
Stack();
Stack(const Stack& org);
~Stack();
int push(T data);
T pop();
};

template<typename T> Stack<T>::Stack() : top(nullptr) {}
// Aufgabe: Bitte eine schnellere Loesung implementieren
template <typename T>Stack<T>::Stack(const Stack& orig) : Stack {} {
   element *ptr = orig.top;
   Stack<T> tmp;

   while(ptr != nullptr){
       tmp.push(ptr->key);
       ptr = ptr->next;
   }
   T k;
   while((k = tmp.pop()) != -1){
       this->push(k);
   }

}
template<typename T>Stack<T>::~Stack(){
    while(this->pop() != -1);
}
template<typename T>int Stack<T>::push(T data){
    element newElement = new Element(data,nullptr);
    if(newElement != nullptr){
        newElement->key = data;
        newElement->next = top;
        top = newElement;
        return 1 ; 
    }
    return 0 ; 
}
template<typename T>T Stack<T>::pop(){
    T erg ; 
    if(top !=nullptr){
        erg = top->key;
        element temp = top; 
        top  = top->next;
        delete temp;
        return erg ; 
    }else{
        throw  empty_stack_exception ("Satck is Empty");
    }      
}
  


}
#endif // !_Stach_H_INCLUDED