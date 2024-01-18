#include <iostream>
#include <string>

using namespace std;

template <typename T>
class ListNode 
{
    public:
        T value;
        ListNode<T>* next;
        ListNode(T val) : value(val), next(nullptr) {}
        friend ostream& operator<<(ostream& out, const ListNode& el)
        {
            out << to_string(el.value);
            return out;
        }
};

template <typename T>
class List 
{
    private:
        ListNode<T>* head;

    public:
        List() : head(nullptr) {}
        
        ListNode<T>* search(T value)
        {
            ListNode<T>* current = head;
            while (current) 
            {
                if (current->value == value) 
                {
                    return current;
                }
                current = current->next;
            }
            return nullptr;
        }

        void Preapend(T value) 
        {
            ListNode<T>* new_node = new ListNode<T>(value);
            new_node->next = head;
            head = new_node;
        }

        ListNode<T>* findPrevious(T value) 
        {
            ListNode<T>* current = head;
            ListNode<T>* previous = nullptr;

            while (current != nullptr) 
            {
                if (current->value == value) 
                {
                    if (current == head)
                    {
                        return head;
                    }
                    else
                    {
                        return previous;
                    }                    
                }
                previous = current;
                current = current->next;
            }

            return nullptr; 
        }

        void remove(T value) 
        {
            if (head && head->value == value) 
            {
                ListNode<T>* temp = head;
                head = head->next;
            }
            else 
            {
                ListNode<T>* current = head;
                while (current && current->next) 
                {
                    if (current->next->value == value) 
                    {
                        ListNode<T>* temp = current->next;
                        current->next = current->next->next;
                        return;
                    }
                    current = current->next;
                }
            }
            temp->next = nullptr;
            delete temp;
        }

        ~List()
        {
            ListNode<T> next = this -> next;
            while (next != nullptr)
            {
                ListNode<T> temp = next->next;
                delete next;
                next = temp;
            }
        }

        friend ostream& operator<<(ostream& out, const List& el)
        {
            out << "[";
            ListNode<T>* current = el.head;
            while (current) 
            {
                out << current->value;
                if (current->next) 
                {
                    out << ", ";
                }
                current = current->next;
            }
            out << "]";
            return out;
        }
};

int main() {
    List<int> my_list;
    my_list.Preapend(5);
    my_list.Preapend(8);
    my_list.Preapend(9);
    cout << my_list << endl;
    cout << (*my_list.findPrevious(5)) << endl;
    my_list.remove(9);
    cout << my_list << endl;
    cout << (*my_list.findPrevious(8)) << endl;
    return 0;
}
