#include <iostream>
using namespace std;

template <class T>
class ListNode2
{
	public:
		T data;
        ListNode2<T> *next;
        ListNode2<T> *prev;

		ListNode2() {

		};

		ListNode2(T d) {
			data = d;
			next = NULL;
			prev = NULL;
		}

		~ListNode2() {

		}
};
