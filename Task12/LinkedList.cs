using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task12
{
    class LinkedList<T>
    {
        Node start;
        Node current_position;

        public void Add(T value)
        {
            Node elem = new Node(value, null);

            if (start == null)
            {
                start = current_position = elem;
            }
            else
            {

                current_position.next = elem;
                current_position = elem;
            }
        }

        public T Remove(int pos)
        {
            Node current = start;
            Node previous = null;

            if (current != null)
            {
                int i = 0;
                while ((i < pos) && (current.next != null))
                {
                    previous = current;
                    current = current.next;
                    i++;
                }

                if (previous == null)
                {
                    //deleted last element in list
                    start = current_position = null;
                }
                else
                {
                    previous.next = current.next;
                }

                return current.data;
            }

            return default(T);
        }
        public Iterator<T> iterator()
        {
            return new ListIterator(this);
        }
        class Node
        {
            public T data;
            public Node next;
            public Node(T data, Node next)
            {
                this.data = data;
                this.next = next;
            }
        }
        class ListIterator : Iterator<T>
        {
            private LinkedList<T> list;
            private int index = 0;

            public ListIterator(LinkedList<T> list)
            {
                this.list = list;
            }

            public bool hasNext()
            {
                Node current = list.start;
                int i = 0;
                while (i++ < index)
                {
                    if (current.next == null)
                    {
                        return false;
                    }
                    current = current.next;
                }
                return true;
            }

            public T next()
            {
                Node current = list.start;
                int i = 0;
                while ((i++ < index))
                {
                    if (current.next == null)
                    {
                        return default(T);
                    }

                    current = current.next;
                }

                index++;
                return current.data;
            }
        }
    }
}

