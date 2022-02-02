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
        fhdo_pk2::LinkedList::node first;
        fhdo_pk2::LinkedList::node last;
        int count;

        class ListIterator : public Iterator
        {
        private:
            node nextInitNode;

        public:
            ListIterator(node nextInitNode) : nextInitNode(nextInitNode) {}
            bool hasNext() override { return nextInitNode != nullptr; }
            const char *next() override
            {
                const char *erg;
                if (hasNext())
                {
                    erg = nextInitNode->data;
                    nextInitNode = nextInitNode->next;
                    return erg;
                }
                return nullptr;
            }
        };

    public:
        LinkedList() : first(nullptr), last(nullptr), count(0) {}
        LinkedList(const LinkedList &orig) : LinkedList()
        {
            node initNode = orig.first;
            while (initNode != nullptr)
            {
                //take a look on this later;
                this->append(initNode->data);
                initNode = initNode->next;
            }
        }
        ~LinkedList() {}
        /* Fuegt den Text (in konstanter Zeit) an der letzten */
        /* Listenposition hinzu. */
        /* Liefert den Wert 1, wenn das Element eingefuegt werden */
        /* konnte. Ansonsten wird der Wert 0 geliefert. */
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

        /* Fuegt ein neues Element an der Position p ein. */
        /* Das erste Element der Liste befindet sich an der */
        /* Position 0. */
        /* Das Element, das sich aktuell an der Position p befindet,*/
        /* wird nach rechts geschoben. */
        /* Falls sich weniger als p Elemente in der Liste befinden, */
        /* wird der Text am Ende angefuegt. */
        int insert(const char *text, int p)
        {
            node newNode = new Node(text, nullptr, nullptr);
            if (p < 0)
            {
                return -1;
            }
            else if (p == 0)
            {
                newNode->next = first;
                first->previous = newNode;
                first = newNode;
                count++;
                return 1;
            }
            else if (p >= count)
            {
                return append(text);
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
                newNode->previous = temp->previous;
                temp->previous = newNode;
                newNode->previous->next = newNode;
                count++;
                return 1;
            }
        }

        /* Loescht das Element an der Position p. Das erste */
        /* Element befindet sich an der Position 0. */
        /* Falls das p-te Element nicht existiert, wird das letzte */
        /* Element geloescht. Die count der geloeschten Elemente */
        /* wird als Funktionswert geliefert. */
        int remove(int p)
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
            else if (p == 0)
            {
                toDelete = first;
                first->next->previous = nullptr;
                first = first->next;
                delete toDelete;
                count--;
                return 1;
            }
            else if (p >= count)
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
                    if (i == p)
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

        /* Liefert den Text an der p-ten Listenposition. */
        /* Das erste Listenelement befindet sich an der Position 0. */
        /* Falls das p-te Element nicht existiert, wird nullptr */
        /* geliefert. */
        const char *get(int p) const
        {
            if (p < 0 || p > count)
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

        /* Berechnet den Index des ersten Elements, das den Text */
        /* text enthaelt. Falls kein Element den gesuchten Text */
        /* enthaelt, wird -1 geliefert. */
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
        /* Liefert den Text des ersten Elements der Liste (in */
        /* konstanter Zeit). */
        const char *getfirst()
        {
            if (count > 0)
                return first->data;
            return nullptr;
        }
        /* Liefert den Text des letzten Elements der Liste (in */
        /* konstanter Zeit). */
        const char *getlast()
        {
            if (count > 0)
                return last->data;
            return nullptr;
        }
        /* Besucht alle Elemente der Liste und ruft fuer jedes */
        /* Element die Funktion work auf. */
        void visit_all(void (*work)(const char *t))
        {
            /* node temp = first;
            while (temp != nullptr)             
            {
                work(temp->data);
                temp = temp->next;
            }
            std::cout << std::endl; */

            //Using Iterator
            Iterator *it = iterator();
            while (it->hasNext())
            {
                work(it->next());
            }
        }
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
        int countElemente()
        {
            return count;
        }

        Iterator *iterator()
        {
            Iterator *it = new ListIterator(first);
            return it;
        }
    };
} // namespace fhdo_pk2
