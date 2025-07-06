#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<b; i+=k)
#define rFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define rFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)
#define pb push_back
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
const int MOD = 1e9+7;

// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

// void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout)
void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ostream& fout) {  // ofstream& fout --> ostream& fout
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode *t = new SinglyLinkedListNode(data);
    if(position == 0) {
        t->next = llist;
        return t;
    }
    SinglyLinkedListNode *p = llist;
    int cpos = 0;
    while(p && cpos < position-1) {
        p = p->next;
        cpos++;
    }
    if(!p && cpos < position-1) {
        cout << "Given position is Out of bound. Can't insert given data." << '\n';
        return llist;
    }
    if(p == nullptr) return t;
    t->next = p->next;
    p->next = t;

    return llist;
}

int main()
{
    ofstream fout("out.txt");  // or simply use cout for terminal output

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    // print_singly_linked_list(llist_head, " ", fout);
    print_singly_linked_list(llist_head, " ", cout);  // Print to terminal
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();

    return 0;
}
