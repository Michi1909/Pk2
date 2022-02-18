#ifndef _ITERATOR_H_INCLUDED
#define _ITERATOR_H_INCLUDED

namespace fhdo_pk2
{
   template <typename T>
   class Iterator
   {
   public:
      virtual bool hasNext() = 0;
      virtual const T *next() = 0;
   };
}

#endif //_ITERATOR_H_INCLUDED
