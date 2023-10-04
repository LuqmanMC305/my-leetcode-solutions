#include <iostream>

using namespace std;

class LinkedList
{
   private:
     struct Node
     {
        int value;
        Node* next;
     };
     Node* head;

   public:
     LinkedList() : head(nullptr) {}
     void append(int newValue);
     void display();
     void reverse();
     ~LinkedList()
     {
        Node* temp;

        while(temp)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
     }
    
};

void LinkedList::append(int newValue)
{
    Node* newNode = new Node;
    newNode->value = newValue;
    newNode->next = nullptr;

    if(!head)
    {
        head = newNode;
    }
    else
    {
        Node* curr = head;

        while((curr->next))
        {
            curr = curr->next;
        }

        curr->next = newNode;
    }
}

void LinkedList::display()
{
    if(!head)
    {
        cout << "Empty list." << endl;
    }
    else
    {
        Node* curr = head;

        while(curr)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }

        cout << endl;
    }
}

void LinkedList::reverse()
{
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }

    head = prev;
}

int main()
{
    LinkedList l1;

    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    l1.append(5);
    
    cout << "Before Reverse:" << endl;
    l1.display();
    l1.reverse();
    cout << "After Reverse:" << endl;
    l1.display();

    return 0;
}