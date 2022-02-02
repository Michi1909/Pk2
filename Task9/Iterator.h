#ifndef _ITERATOR_H_INCLUDED
#define _ITERATOR_H_INCLUDED

namespace fhdo_pk2{
class Iterator{
public :
   virtual bool hasNext() = 0;
   virtual const char* next() = 0; 
};
}










#endif//_ITERATOR_H_INCLUDED
