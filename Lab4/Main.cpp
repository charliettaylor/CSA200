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
    int test[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    // insertKey(test, 10, 7); // Idx 4
    // insertKey(test, 10, 12);// Idx 9
    // insertKey(test, 10, 3); // Idx 2
    // insertKey(test, 10, 4); // Idx 5
    // insertKey(test, 10, 5); // Idx 8
    // insertKey(test, 10, 10); // Idx 3
    // insertKey(test, 10, 6); // Idx 1
    // insertKey(test, 10, 9); // Idx 0
    // insertKey(test, 10, 8); // Idx 7
    // insertKey(test, 10, 14); // Idx 6

    insertKey(test, 10, 9);
    insertKey(test, 10, 29);
    insertKey(test, 10, 19);
    insertKey(test, 10, 39);
    insertKey(test, 10, 49);

	printTable(test, 10);

    cout << "Search worky?: " << searchKey(test, 10, 19) << "\n";

	deleteKey(test, 10, 29);
    printTable(test, 10);
	cout << "\n";
	insertKey(test, 10, 6);
    printTable(test, 10);

	return 0;
}

int hashValue(int key, int j, int capacity)
{
    return ((3 * key) + 3 + j) % capacity;
}

void insertKey(int array[], int capacity, int key)
{
    bool done = false;
    bool inserted = false;
    int count = 0;
    int idx = hashValue(key, count, capacity);

    while(!done)
    {
        if(count >= (capacity / 3))
        {
			done = true;
		}
        else if(array[idx] == -2 || array[idx] == -1)
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
