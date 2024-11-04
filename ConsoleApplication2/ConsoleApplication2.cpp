
#include <iostream>
using namespace std;
struct Node {
	Node* next;
	int value;
	Node(int value,Node* next):next(nullptr),value(value){}


	
};
class List {
	Node* head;
public:
	List() : head(nullptr){}
	~List() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void addtohead(int value) {
		Node* newNode = new Node(value, head);
		newNode->next = head;
		head = newNode;
	}
	void addtotail(int value) {
		Node* newNode = new Node(value, nullptr);
		Node* current = head;
		if (head == nullptr) {
			head = newNode;
			addtohead(value);
			return;
		}
		else {
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void deletefromhead() {
		if (!head)return;
		Node* temp = head;
		head = head->next;
		delete temp;
		if (!head) {

		}
	}
	void deletefromtail() {
		if (head->next == nullptr) {
			delete head;
			head = nullptr;

		}
		else {
			Node* current = head;
			while (current->next->next != nullptr) {
				current = current->next;

			}
			delete current->next;
			current->next = nullptr;
		}
	}
	void deleteall() {
		while (head) {
			deletefromhead();
		}
	}
	void Show() const {
		Node* current = head;
		while (current != nullptr) {
			cout << current->value << "";
			current = current->next;
		}
	}
	List operator+=(const List& other) const  {
		List result = *this;
		result += other;
		return result;




	}
	List operator*(const List& other) const {
		List result;
		Node* current1 = head;
		Node* current2 = other.head;
		while (current1 && current2) {
			current1 = current1->next;
			current2 = current2->next;
		}
		return result;
	}
};
int main()
{
	List list;
	list.addtohead(3);
	list.addtohead(6);
	list.addtohead(9);

	List list2;
	list2.addtohead(5);
	list2.addtohead(1);
	list2.addtohead(7);

	cout << "List 1" << endl;
	list.Show();

	cout << "List 2" << endl;
	list2.Show();

	List merged = list * list2;
	cout << "Cout element " << endl;
	merged.Show();

}

