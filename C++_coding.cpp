#include <iostream>
#include<string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Reverse linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

// Remove leading zeros
Node* trimLeadingZeros(Node* head) {
    while (head && head->data == 0)
        head = head->next;

    return head ? head : new Node(0);
}

// Build list from string number
Node* buildListFromString(const string& s) {
    Node* head = NULL;
    Node* tail = NULL;

    for (char c : s) {
        Node* node = new Node(c - '0');
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Add two numbers
Node* addTwoLists(Node* num1, Node* num2) {
    num1 = trimLeadingZeros(num1);
    num2 = trimLeadingZeros(num2);

    num1 = reverseList(num1);
    num2 = reverseList(num2);

    Node* res = NULL;
    Node* curr = NULL;
    int carry = 0;

    while (num1 || num2 || carry) {
        int sum = carry;
        if (num1) sum += num1->data, num1 = num1->next;
        if (num2) sum += num2->data, num2 = num2->next;

        Node* node = new Node(sum % 10);
        carry = sum / 10;

        if (!res) res = curr = node;
        else curr->next = node, curr = node;
    }

    return reverseList(res);
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;   // INPUT: 123 999

    Node* num1 = buildListFromString(s1);
    Node* num2 = buildListFromString(s2);

    Node* result = addTwoLists(num1, num2);
    printList(result);

    return 0;
}