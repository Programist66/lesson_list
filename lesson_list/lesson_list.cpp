#include <iostream>

using namespace std;

class ListNode 
{
    public:
        int value;
        ListNode* next;
        ListNode(int val) : value(val), next(nullptr) {}
};

class List 
{
    private:
        ListNode* head;

    public:
        List() : head(nullptr) {}
        
        ListNode* search(int value)
        {
            ListNode* current = head;
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

        void Preapend(int value) 
        {
            ListNode* new_node = new ListNode(value);
            new_node->next = head;
            head = new_node;
        }

        ListNode* findPrevious(int value) 
        {
            ListNode* current = head;
            ListNode* previous = nullptr;

            while (current != nullptr) 
            {
                if (current->value == value) 
                {
                    return previous;
                }
                previous = current;
                current = current->next;
            }

            return nullptr; // Возвращаем nullptr, если значение не найдено
        }

        friend ostream& operator<<(ostream& out, const List& el)
        {
            out << "[";
            ListNode* current = el.head;
            while (current) 
            {
                out << current->value;
                if (current->next) 
                {
                    out << ", ";
                }
                current = current->next;
            }
            out << "]\n";
            return out;
        }
};

int main() {
    List my_list;
    my_list.Preapend(5);
    my_list.Preapend(8);
    my_list.Preapend(9);
    cout << my_list;
    cout << my_list.findPrevious(8);
    return 0;
}
