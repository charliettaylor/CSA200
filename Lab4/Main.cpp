/*
    Taylor, Charlie
    Ziller, Joseph
    
    4/11/2021

    CS A200
    Project 4 Hash Tables
*/

#include <iostream>
#include <vector>

using namespace std;

const int CAPACITY = 21;

int hashValue(int key, int j, int capacity);

void insertKey(int array[], int capacity, int key);

bool searchKey(const int array[], int capacity, int key);

void deleteKey(int array[], int capacity, int key);

void printTable(const int array[], int capacity);

int main()
{
    int test[CAPACITY] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    int cap = CAPACITY;

    vector<int> insertKeys = {7, 12, 3, 4, 5, 10, 6, 9, 8, 14};
    
    for(const auto i : insertKeys)
    {
        insertKey(test, cap, i);
    }

    printTable(test, cap);
    cout << "------------------------------\n";

    cout << "Looking for 19...\n";
    cout << "Search work? (1/0): "
         << searchKey(test, cap, 19) << "\n";

    cout << "Looking for 12...\n";
    cout << "Search work? (1/0): "
         << searchKey(test, cap, 12) << "\n";
    
    printTable(test, cap);
    cout << "------------------------------\n";


    cout << "Deleting 14...\n";

    deleteKey(test, cap, 14);
    cout << "Looking for 14...\n";
    cout << "Search work? (1/0): "
         << searchKey(test, cap, 14) << "\n";
    
    printTable(test, cap);
    cout << "------------------------------\n";
    
    cout << "Deleting 111...\n";

    deleteKey(test, cap, 111);
    printTable(test, cap);

    cout << "------------------------------\n";

	return 0;
}

int hashValue(int key, int j, int capacity)
{
    //linear probing
    return ((3 * key) + 3 + j) % capacity;

    //linear probing step size 5
    //return ((3 * key) + 3 + (j * 5)) % capacity;

    //quadratic
    //return ((3 * key) + 3 + (j * j)) % capacity;
    
    //double hashing
    //return ((((3 * key) + 3 + j) % capacity) + j 
        //* (11 - (key % 11))) % capacity;
}

void insertKey(int array[], int capacity, int key)
{
    bool inserted = false;
    int count = 0;
    int idx = hashValue(key, count, capacity);

    while(count <= (capacity / 3) && !inserted)
    {
        if(array[idx] == -2 || array[idx] == 0 || array[idx] == key)
        {
            array[idx] = key;
            inserted = true;
        }
        else
        {
            ++count;
            idx = hashValue(key, count, capacity);
        }
    }

    if(!inserted)
    {
        cerr << "Could not insert key " << key
             << ". Need to rehash.\n";
    }
}

bool searchKey(const int array[], int capacity, int key)
{
	bool done = false;
	bool found = false;
    int count = 0;
    int idx = hashValue(key, count, capacity);

    while(!done)
    {
        if(array[idx] == key)
        {
            done = true;
            found = true;
        }
        else if(array[idx] == 0 || count >= (capacity / 3))
        {
            done = true;
        }
        else
        {
            ++count;
            idx = hashValue(key, count, capacity);
        }
    }

    return found;
}

void deleteKey(int array[], int capacity, int key)
{
	bool done = false;
	bool deleted = false;
    int count = 0;
    int idx = hashValue(key, count, capacity);

    while(!done)
    {
        if(array[idx] == key)
        {
            done = true;
            deleted = true;
            array[idx] = -2;
        }
        else if(array[idx] == 0)
        {
            done = true;
        }
        else
        {
            count += 1;
            idx = hashValue(key, count, capacity);
        }
    }
}

void printTable(const int array[], int capacity)
{
    for(int i = 0; i < capacity; ++i)
    {
        cout << "IDX " << i << " = " << array[i] << "\n";
    }
}
