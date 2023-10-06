#include <iostream>

using namespace std;

class LinkedList
{
    private:
      struct Node
      {
         int val;
         Node* next;
      };

    public:
      Node* head;

      LinkedList() : head(nullptr) {}
      ~LinkedList()
      {
        Node* temp;

        while(head)
        {
           temp = head;
           head = head->next;
           delete temp;
        }
      }
      void append(int newVal);
      void display();
      void merge(LinkedList &l1, LinkedList &l2);
};

void LinkedList::append(int newVal)
{
    Node* newNode = new Node;
    newNode->val = newVal;
    newNode->next = nullptr;

    if(!head)
    {
        head = newNode;
    }
    else
    {
        Node* curr = head;

        while(curr->next)
        {
            curr = curr->next;
        }

        curr->next = newNode;
    }
}

void LinkedList::display()
{
    Node* curr = head;

    while(curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }

    cout << endl;
}

void LinkedList::merge(LinkedList &l1, LinkedList &l2)
{
    Node* curr1 = l1.head;
    Node* curr2 = l2.head;

    if(!curr1)
    {
        append(curr2->val);
        curr2 = curr2->next;
    }

    if(!curr2)
    {
        append(curr1->val);
        curr1 = curr1->next;
    }

    while(curr1 && curr2)
    {
        if(curr1->val <= curr2->val)
        {
            append(curr1->val);
            curr1 = curr1->next;
        }
        else
        {
            append(curr2->val);
            curr2 = curr2->next;
        }
    }
    

    while(curr1)
    {
        append(curr1->val);
        curr1 = curr1->next;
    }

     while(curr2)
    {
        append(curr2->val);
        curr2 = curr2->next;
    }

   
}



int main()
{
    LinkedList l1, l2, l3;
    l1.append(1);
    l1.append(2);
    l1.append(4);

    l2.append(4);
    l2.append(5);
    l2.append(6);

    l3.merge(l1, l2);
    l3.display();


    return 0;
}