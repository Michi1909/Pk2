#include <iostream>
#include "Iterator.h"

namespace fhdo_pk2
{
    class LinkedList
    {
    private:
        struct Node
        {
            const char *data;
            Node *next;
            Node *previous;
            Node(const char *data, Node *next, Node *previous) : data(data), next(next), previous(previous) {}
            ~Node() {}
        };
        typedef struct Node *node;
        node first;
        node last;
        int count;

        class ListIterator : public Iterator
        {
        private:
            node nextNode;

        public:
            ListIterator(node nextNode) : nextNode(nextNode) {}
            bool hasNext() override
            {
                return nextNode != nullptr;
            }
            const char *next() override
            {
                const char *erg;
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
        LinkedList() : first(nullptr), last(nullptr), count(0) {}
        LinkedList(const LinkedList &org) : LinkedList()
        {
            node temp = org.first;

            while (temp != nullptr)
            {
                this->append(temp->data);
                temp = temp->next;
            }
        }
        ~LinkedList() {}

        //this Funkion must add Text in Constanter Time on The Last Postion in The List ;
        int append(const char *text)
        {
            node newNode = new Node(text, nullptr, nullptr);
            // add first
            if (first == nullptr)
            {
                first = last = newNode;
                count++;
                return 1;
                // add at the End "append"
            }
            else
            {
                last->next = newNode;
                newNode->previous = last;
                last = newNode;
                count++;
                return 1;
            }
        }
        // this Funtion must add Text in The place P
        int insert(const char *text, int position)
        {
            node newNode = new Node(text, nullptr, nullptr);
            if (position < 0)
            {
                return -1;
            }
            else if (position == 0)
            {
                newNode->next = first;
                first->previous = newNode;
                first = newNode;
                count++;
                return 1;
            }
            else if (position >= count)
            {
                return append(text);
            }
            else
            {
                node temp = first;
                int i = 0;
                while (i < position)
                {
                    i++;
                    temp = temp->next;
                }
                newNode->next = temp;
                newNode->previous = temp->previous;
                temp->previous = newNode;
                newNode->previous->next = newNode;
                count++;
                return 1;
            }
        }
        // Delete Method on the Place P
        int remove(int position)
        {
            node toDelete;
            if (count == 0)
            {
                return -1;
            }
            else if (count == 1)
            {
                toDelete = first;
                first = last = nullptr;
                delete toDelete;
                count--;
                return 1;
            }
            else if (position == 0)
            {
                toDelete = first;
                first->next->previous = nullptr;
                first = first->next;
                delete toDelete;
                count--;
                return 1;
            }
            else if (position >= count)
            {
                toDelete = last;
                last->previous->next = nullptr;
                last = last->previous;
                delete toDelete;
                count--;
                return 1;
            }
            else
            {
                node temp = first;
                int i = 0;
                while (temp != nullptr)
                {
                    if (i == position)
                    {
                        toDelete = temp;
                        temp->previous->next = temp->next;
                        temp->next->previous = temp->previous;
                        delete toDelete;
                        count--;
                        return 1;
                    }
                    temp = temp->next;
                    i++;
                }
            }
        }
        //this Funktion should bing back the Text on the place p
        const char *get(int position) const
        {
            if (position < 0 || position > count)
            {
                return nullptr;
            }
            else
            {
                node temp = first;
                int i = 0;
                while (temp != nullptr)
                {
                    if (i == position)
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
        int index_of(const char *text)
        {
            node temp = first;
            while (temp != nullptr)
            {
                int index = 0;
                if (text == temp->data)
                {
                    return index;
                }
                temp = temp->next;
                index++;
            }
            return -1;
        }
        // get the first Text in the List
        const char *getfirst()
        {
            if (count > 0)
                return first->data;
            return nullptr;
        }
        //get Last Text in The List
        const char *getlast()
        {
            if (count > 0)
                return last->data;
            return nullptr;
        }
        //visting
        void visit_all(void (*work)(const char *t))
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
        // printig
        void printList()
        {
            node temp = first;
            while (temp != nullptr)
            {
                std::cout << temp->data << "\t";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        // count Elemnte
        int countElements()
        {
            return count;
        }
        // Iterator
        Iterator *iterator()
        {
            Iterator *it = new ListIterator(first);
            return it;
        }
    };
}
