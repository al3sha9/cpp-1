#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
};

struct HashMap {
    int numOfElements;
    int capacity;
    vector<Node*> arr;

    HashMap(int cap) : numOfElements(0), capacity(cap), arr(cap, nullptr) {}
};

int hashFunction(HashMap* mp, const string& key) {
    int sum = 0;
    int factor = 31;
    for (char ch : key) {
        sum = ((sum % mp->capacity) + ((ch * factor) % mp->capacity)) % mp->capacity;
        factor = (factor * 31) % numeric_limits<int>::max();
    }
    return sum;
}

void insert(HashMap* mp, const string& key, const string& value) {
    int bucketIndex = hashFunction(mp, key);
    Node* newNode = new Node{key, value, nullptr};
    if (mp->arr[bucketIndex] == nullptr) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

void deleteKey(HashMap* mp, const string& key) {
    int bucketIndex = hashFunction(mp, key);
    Node* prevNode = nullptr;
    Node* currNode = mp->arr[bucketIndex];
    while (currNode != nullptr) {
        if (currNode->key == key) {
            if (prevNode == nullptr) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            delete currNode;
            mp->numOfElements--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

string search(HashMap* mp, const string& key) {
    int bucketIndex = hashFunction(mp, key);
    Node* bucketHead = mp->arr[bucketIndex];
    while (bucketHead != nullptr) {
        if (bucketHead->key == key) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Oops! No data found.";
}

int main() {
    HashMap* mp = new HashMap(100);
    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "GeeksforGeeks");
    insert(mp, "decentBoy", "Mayank");

    cout << search(mp, "elite_Programmer") << endl;
    cout << search(mp, "Yogaholic") << endl;
    cout << search(mp, "pluto14") << endl;
    cout << search(mp, "decentBoy") << endl;
    cout << search(mp, "GFG") << endl;
    cout << search(mp, "randomKey") << endl;

    cout << "\nAfter deletion : \n";

    deleteKey(mp, "decentBoy");
    cout << search(mp, "decentBoy") << endl;

    // Clean up memory
    for (Node* node : mp->arr) {
        while (node != nullptr) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
    }
    delete mp;

    return 0;
}
