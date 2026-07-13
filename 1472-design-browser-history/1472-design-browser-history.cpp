class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int v) {
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:
    unordered_map<int, string> mpp;
    int pages;
    Node* currNode;
    Node* tail;
    BrowserHistory(string homepage) {
        pages = 1;
        Node* head = new Node(1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
        currNode = head;
        mpp[1] = homepage;
    }

    void visit(string url) {
        currNode->next = tail;
        tail->prev = currNode;
        Node* newNode = new Node(currNode->val + 1);
        newNode->prev = currNode;
        newNode->next = tail;
        currNode->next = newNode;
        tail->prev = newNode;

        currNode = newNode;
        pages = newNode->val;
        mpp[currNode->val] = url;
    }

    string back(int steps) {
        int tmp = steps;
        while (tmp > 0 && currNode->prev) {
            currNode = currNode->prev;
            tmp--;
        }
        return mpp[currNode->val];
    }

    string forward(int steps) {
        int tmp = steps;
        while (tmp > 0 && currNode->next->next) {
            currNode = currNode->next;
            tmp--;
        }
        return mpp[currNode->val];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */