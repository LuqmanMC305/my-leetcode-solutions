#include <iostream>

using namespace std;

class MyHashMap
{   
    private:
      int size;
      int* map;
    public:
      MyHashMap(int size)
      {
         this->size = size;
         map = new int[size];

         for(int i; i < size; i++)
         {
            map[i] = -1;
         }
      }
      ~MyHashMap() {delete[] map;}
      void put(int key, int value);
      int get(int key);
      void remove(int key); 
    

};

void MyHashMap::put(int key, int value)
{
    map[key] = value;
}

int MyHashMap::get(int key)
{
    if (key < 0 || key >= size)
    {
        cout << "Key out of bounds." << endl;
        return -1;
    }
    return map[key];
}

void MyHashMap::remove(int key)
{
    if (key < 0 || key >= size)
    {
        cout << "Key out of bounds." << endl;
        return;
    }
    map[key] = -1;
}

int main()
{
    MyHashMap map1(20);

    map1.put(1, 10);
    map1.put(2, 20);
    map1.put(3, 300);
    

    cout << map1.get(1);

    return 0;
}