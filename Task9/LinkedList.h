#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include "Iterator.h"

namespace fhdo_pk2
{
    template <typename T>
    class LinkedList
    {
    private:
        struct Node
        {
            T data;
            Node *next;
            Node *before;
            Node(T data, Node *next, Node *before) : data(data), next(next), before(before) {}
            ~Node();
        };

        typedef struct Node *node;
        node first;
        node last;
        int anzahl;

        template <typename T>
        class ListIterator<T> : public Iterator
        {
        private:
            node nextNode;

        public:
            ListIterator(node nextNode) : nextNode(nextNode) {}
            bool hasNext() override
            {
                return nextNode != nullptr;
            }
            const T next() override
            {
                T erg;
                if (hasNext())
                {
                    erg = nextNode->data;
                    nextNode = nextNode->next;
                    return erg;
                }
                return nullptr;
            }
        };

    public:
        LinkedList();
        LinkedList(const LinkedList &org);
        ~LinkedList();

        // this Funkion must add Text in Constanter Time on The Last Postion in The List ;
        int append(T inhalt);
        // this Funtion must add Text in The place P
        int insert(T inhalt, int p);
        // Delete Method on the Place P
        int remove(int p);
        // this Funktion should bing back the Text on the place p
        T get(int p) const;
        // calculate The index  of a Text
        int index_of(T inhalt);
        // get the first Text in the List
        T getfirst() const;
        // get Last Text in The List
        T getlast() const;
        // visting
        void visit_all(void (*work)(T t));
        // printig
        void printList();
        // anzahl Elemnte
        int anzahlElemente();
        // Iterator
        Iterator<T> *iterator();
    };
    template <typename T>
    LinkedList<T>::LinkedList() : first(nullptr), last(nullptr), anzahl(0) {}
    template <typename T>
    LinkedList<T>::LinkedList(const LinkedList &org) : LinkedList()
    {
        node temp = org.first;

        while (temp != nullptr)
        {
            this->append(temp->data);
            temp = temp->next;
        }
    }
    template <typename T>
    LinkedList<T>::~LinkedList() {}

    // this Funkion must add Text in Constanter Time on The Last Postion in The List ;
    template <typename T>
    int LinkedList<T>::append(T inhalt)
    {
        node newNode = new Node(inhalt, nullptr, nullptr);
        // add first
        if (first == nullptr)
        {
            first = last = newNode;
            anzahl++;
            return 1;
            // add at the End "append"
        }
        else
        {
            last->next = newNode;
            newNode->before = last;
            last = newNode;
            anzahl++;
            return 1;
        }
    }
    // this Funtion must add Text in The place P
    template <typename T>
    int LinkedList<T>::insert(T inhalt, int p)
    {
        node newNode = new Node(inhalt, nullptr, nullptr);
        if (p < 0)
        {
            return -1;
        }
        else if (p == 0)
        {
            newNode->next = first;
            first->before = newNode;
            first = newNode;
            anzahl++;
            return 1;
        }
        else if (p >= anzahl)
        {
            return append(inhalt);
        }
        else
        {
            node temp = first;
            int i = 0;
            while (i < p)
            {
                i++;
                temp = temp->next;
            }
            newNode->next = temp;
            newNode->before = temp->before;
            temp->before = newNode;
            newNode->before->next = newNode;
            anzahl++;
            return 1;
        }
    }
    // Delete Method on the Place P
    template <typename T>
    int LinkedList<T>::remove(int p)
    {
        node toDelete;
        if (anzahl == 0)
        {
            return -1;
        }
        else if (anzahl == 1)
        {
            toDelete = first;
            first = last = nullptr;
            delete toDelete;
            anzahl--;
            return 1;
        }
        else if (p == 0)
        {
            toDelete = first;

            first = first->next;
            delete toDelete;
            anzahl--;
            return 1;
        }
        else if (p >= anzahl)
        {
            toDelete = last;
            last->before->next = nullptr;
            last = last->before;
            delete toDelete;
            anzahl--;
            return 1;
        }
        else
        {
            node temp = first;
            int i = 0;
            while (temp != nullptr)
            {
                if (i == p)
                {
                    toDelete = temp;
                    temp->before->next = temp->next;
                    temp->next->before = temp->before;
                    delete toDelete;
                    anzahl--;
                    return 1;
                }
                temp = temp->next;
                i++;
            }
        }
    }
    // this Funktion should bing back the Text on the place p
    template <typename T>
    T LinkedList<T>::get(int p) const
    {
        if (p < 0 || p > anzahl)
        {
            return nullptr;
        }
        else
        {
            node temp = first;
            int i = 0;
            while (temp != nullptr)
            {
                if (i == p)
                {
                    return temp->data;
                }
                temp = temp->next;
                i++;
            }
            return nullptr;
        }
    }
    // calculate The index  of a Text
    template <typename T>
    int LinkedList<T>::index_of(T inhalt)
    {
        node temp = first;
        while (temp != nullptr)
        {
            int index = 0;
            if (inhalt == temp->data)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }
    // get the first Text in the List
    template <typename T>
    T LinkedList<T>::getfirst() const
    {
        if (anzahl > 0)
            return first->data;
        return nullptr;
    }
    // get Last Text in The List
    template <typename T>
    T LinkedList<T>::getlast() const
    {
        if (anzahl > 0)
            return last->data;
        return nullptr;
    }
    // visting
    template <typename T>
    void LinkedList<T>::visit_all(void (*work)(T t))
    {
        /* Normal Iteration
            node temp = first;
            while(temp!=nullptr){
                work(temp->data);
                temp  = temp->next;
            }
           std::cout<<std::endl;
           */
        // Mit Iterator

        Iterator *it = iterator();
        while (it->hasNext())
        {
            work(it->next());
        }
    }
    // printing
    template <typename T>
    void LinkedList<T>::printList()
    {
        node temp = first;
        while (temp != nullptr)
        {
            std::cout << temp->data << "\t";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    // anzahl Elemnte
    template <typename T>
    int LinkedList<T>::anzahlElemente()
    {
        return anzahl;
    }
    // Iterator
    template <typename T>
    Iterator<T> *LinkedList<T>::iterator()
    {
        ListIterator<T> *it = new ListIterator(first);
        return it;
    }

} // namespace fhdo_pk2
#endif // LINKEDLIST_H_INCLUDED