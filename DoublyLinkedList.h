#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList {
	public:

		ListNode<T> *front;
		ListNode<T> *back;
		unsigned int size;

		DoublyLinkedList() {
			size = 0;
			front = NULL;
			back = NULL;
		}

		~DoublyLinkedList() {

		};

		void insertBack(T d) {
			ListNode<T> *node = new ListNode<T>(d);

			// IF LIST IS EMPTY
			if (size == 0) {
				front = node;
			} else {
				back->next = node;
				node->prev = back;
			}

			back = node;
			size++;
		}

		T removeFront() {
		    if (!isEmpty()) {
				ListNode<T> *oldFront = front;

			    T oldData = oldFront->data;

			    // IF THERE IS ONLY ONE ELEMENT
				if (front->next == NULL) {
			        front = NULL;
			        back = NULL;
				} else {
					// MORE THAN ONE ELEMENT
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

		void removeAt(int pos) {
			int index = 0;
			ListNode<T> *current = front;
			ListNode<T> *previous = front;

			while (index != pos) {
				previous = current;
				current = current->next;
				++index;
			}

			// WE FOUND WHAT NEEDS TO BE DELETED
			previous->next = current->next;
			current->next->previous = previous;
			current->next = NULL;
			current->previous = NULL;
			current->data = NULL;

			size--;
			delete current;
		}

		T getFront() {
			return front->data;
		}

		void printList() {
			ListNode<T> *current = front;

			while (true)
			{
				if (current->next == NULL)
				{
					break;
				}

				cout << current->data << ", ";
				current = current->next;
			}
		}

		int getSize() {
			return size;
		}

        bool isEmpty() {
		    return (size == 0);
		}
};
