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
    int test[CAPACITY] = {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };

    vector<int> insertKeys = {7, 12, 3, 4, 5, 10, 6, 9, 8, 14};
    
    for(const auto i : insertKeys)
    {
        insertKey(test, CAPACITY, i);
    }

    // insertKey(test, CAPACITY, 7); // Idx 4
    // insertKey(test, CAPACITY, 12);// Idx 9
    // insertKey(test, CAPACITY, 3); // Idx 2
    // insertKey(test, CAPACITY, 4); // Idx 5
    // insertKey(test, CAPACITY, 5); // Idx 8
    // insertKey(test, CAPACITY, 10); // Idx 3
    // insertKey(test, CAPACITY, 6); // Idx 1
    // insertKey(test, CAPACITY, 9); // Idx 0
    // insertKey(test, CAPACITY, 8); // Idx 7
    // insertKey(test, CAPACITY, 14); // Idx 5

    //Initial Tests
    // insertKey(test, CAPACITY, 9);
    // insertKey(test, CAPACITY, 29);
    // insertKey(test, CAPACITY, 19);
    // insertKey(test, CAPACITY, 39);
    // insertKey(test, CAPACITY, 49);

	// printTable(test, CAPACITY);

    // cout << "Search worky?: " << searchKey(test, CAPACITY, 19) << "\n";

	// deleteKey(test, CAPACITY, 29);
    // printTable(test, CAPACITY);
	// cout << "\n";
	// insertKey(test, CAPACITY, 6);

    //Step Size 5 Tests
    
    printTable(test, CAPACITY);

	return 0;
}

int hashValue(int key, int j, int capacity)
{
    return ((3 * key) + 3 + j) % capacity;
    //return ((3 * key) + 3 + (j * 5)) % capacity;
    //return ((3 * key) + 3 + j^2) % capacity;
    //return ((((3 * key) + 3 + j) % capacity) + j * (11 - (key % 11)))
            //% capacity;
}

void insertKey(int array[], int capacity, int key)
{
    bool done = false;
    bool inserted = false;
    int count = 0;
    int idx = hashValue(key, count, capacity);

    while(count <= (capacity / 3) && !done)
    {
        if(array[idx] == -2 || array[idx] == -1)
        {
            array[idx] = key;
            done = true;
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
        cout << "Could not insert key " << key << ". Need to rehash.\n";
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
        else if(array[idx] == -1)
        {
            done = true;
        }
        else
        {
            count += 1;
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
        else if(array[idx] == -1)
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
