#include <iostream>
#include "ListNode2.h" //uses a different list node than the DoublyLinkedList

using namespace std;

template <class T>
class Queue
{
	public:
		ListNode2<T> *front;
		ListNode2<T> *back;
		unsigned int size;

		Queue() {
			size = 0;
			front = NULL;
			back = NULL;
		}

		~Queue() {

		};

		void enqueue(T d) {
			ListNode2<T> *node = new ListNode2<T>(d);

			// IF LIST IS EMPTY
			if (size == 0) {
				front = node;
			} else {
				back->next = node;
				node->prev = back;
			}

			back = node;
			++size;
		}

		T dequeue() {
		    if (!isEmpty()) {
				ListNode2<T> *oldFront = front;

			    T oldData = oldFront->data;

			    // IF THERE IS ONLY ONE ELEMENT
				if (front->next == NULL) {
			        front = NULL;
			        back = NULL;
				} else { // MORE THAN ONE ELEMENT
					front->next->prev = NULL;

			        front = front->next;
				}

				delete oldFront;

				size--;
				return oldData;
		    } else {
				return T();
			}
		}

		T getFront() {
			return front->data;
		}

		T getBack() {
			return back->data;
		}

		void printQueue() {
			ListNode2<T> *current = front;

			while (true) {
				if (current == NULL) {
					break;
				}

				cout << current->data << endl;
				current = current->next;
			}
		}

		unsigned int getSize() {
			return size;
		}

        bool isEmpty() {
		    return (size == 0);
		}
};
