#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class StringList
{
  public:
    StringList(string text);
    // You may declare other member functions for your test code to call
    void eraseThrees();
    void dump() const;
    ~StringList();
  private:
    struct Node
    {
      char  value;
      Node* next;
      Node(char v, Node* n) : value(v), next(n) {}
    };
    Node* head;  // points to first Node in the list
};

StringList::StringList(string text)
{
    //  For example, StringList s("heap"); creates s containing
    //  a list with values  'h'  'e'  'a'  'p'
  head = nullptr;
  for (int k = text.size(); k > 0; k--)
    head = new Node(text[k-1], head);
}

// You may implement other member functions here for test purposes,
// but you will not turn them in as part of your submission.

StringList::~StringList() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
}

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AFTER THE END OF THE eraseThrees IMPLEMENTATION

void StringList::eraseThrees() {
    int counter = 1;
    Node *p = head;
    Node *prev = nullptr;
    while (p != nullptr) {
        if (counter % 3 == 0) {
            // delete node that p points to
            prev->next = p->next;
            delete p;
        }
        else {
            prev = p;
        }
        p = prev->next;
        counter++;
    }
}

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT BEFORE THE START OF THE eraseThrees IMPLEMENTATION

void StringList::dump() const {
    Node *p = head;
    while (p!=nullptr) {
        cerr << p->value << " ";
        p = p->next;
    }
    cerr << endl;
}

int main()
{
    StringList x("treachery");
    x.eraseThrees();
    x.dump();
    StringList s("a");
    s.eraseThrees();
    s.dump();
    StringList a("");
    a.eraseThrees();
    a.dump();
    StringList b("it's over han");
    b.eraseThrees();
    b.dump();
  // You might put some code here for test purposes, e.g., to verify
  // that x now contains  't'  'r'  'a'  'c'  'e'  'r'
  // You might run some other tests.
  cout << "Program finished" << endl;
}
