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
      void add(LinkedList &l1, LinkedList &l2);
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

void LinkedList::add(LinkedList &l1, LinkedList &l2)
{
    Node* curr1 = l1.head;
    Node* curr2 = l2.head;
    int carry = 0;
    int sum;

    while(curr1 || curr2 || carry) // same as carry != 0
    {
       sum = (curr1 ? curr1->val : 0) + (curr2 ? curr2->val : 0) + carry;

       carry = (sum >= 10 ? 1 : 0);

       append(sum % 10);

       if(curr1)
       {
         curr1 = curr1->next;
       }

       if(curr2)
       {
         curr2 = curr2->next;
       }
       
    }

}


int main()
{
    LinkedList l1, l2, l3;
    l1.append(9);
  
    l2.append(9);
    l2.append(9);
    l2.append(9);


    l3.add(l1, l2);
    l3.display();


    return 0;
}