#include <iostream>
using namespace std;

template <class T>
class ListNode
{
	public:
		T data;
        ListNode<T> *next;
        ListNode<T> *prev;

		ListNode() {

		};

		ListNode(T d) {
			data = d;
			next = NULL;
			prev = NULL;
		}

		~ListNode() {
			
		}
};
