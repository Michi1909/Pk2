#include <iostream>

namespace fhdo_pk2
{
    class LinkedList
    {
    private:
        struct Node
        {
            const char *data;
            Node *next;
            Node *before;
            Node(const char *data, Node *next, Node *before) : data(data), next(next), before(before) {}
            ~Node() {}
        };
        typedef struct Node *node;
        fhdo_pk2::LinkedList::node first;
        fhdo_pk2::LinkedList::node last;
        int anzahl;

    public:
        /* Erzeugt eine leere Liste. */
        LinkedList() : first(nullptr), last(nullptr), anzahl(0) {}
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
                first->before = newNode;
                first = newNode;
                anzahl++;
                return 1;
            }
            else if (p >= anzahl)
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
                newNode->before = temp->before;
                temp->before = newNode;
                newNode->before->next = newNode;
                anzahl++;
                return 1;
            }
        }

        /* Loescht das Element an der Position p. Das erste */
        /* Element befindet sich an der Position 0. */
        /* Falls das p-te Element nicht existiert, wird das letzte */
        /* Element geloescht. Die Anzahl der geloeschten Elemente */
        /* wird als Funktionswert geliefert. */
        int remove(int p)
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
                first->next->before = nullptr;
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

        /* Liefert den Text an der p-ten Listenposition. */
        /* Das erste Listenelement befindet sich an der Position 0. */
        /* Falls das p-te Element nicht existiert, wird nullptr */
        /* geliefert. */
        const char *get(int p) const
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

        /* Berechnet den Index des ersten Elements, das den Text */
        /* text enthaelt. Falls kein Element den gesuchten Text */
        /* enthaelt, wird -1 geliefert. */
        int index_of(const char *text)
        {
            node temp = first;
            int index = 0;
            while (temp != nullptr)
            {

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
            if (anzahl > 0)
                return first->data;
            return nullptr;
        }
        /* Liefert den Text des letzten Elements der Liste (in */
        /* konstanter Zeit). */
        const char *getlast()
        {
            if (anzahl > 0)
                return last->data;
            return nullptr;
        }
        /* Besucht alle Elemente der Liste und ruft fuer jedes */
        /* Element die Funktion work auf. */
        void visit_all(void (*work)(const char *t))
        {
            node temp = first;
            while (temp != nullptr)
            {
                work(temp->data);
                temp = temp->next;
            }
            std::cout << std::endl;
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
        // anzahl Elemnte
        int anzahlElemente()
        {
            return anzahl;
        }
    };
} // namespace fhdo_pk2
