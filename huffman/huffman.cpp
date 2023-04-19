//
// Created by 안진우 on 2023/04/19.
//
#include "huffman.h"
#define character first
#define count second
using namespace std;


Huffman::~Huffman() {
    stack<Node*> s;
    s.push(binTree);

    while(!s.empty()) {
        Node* cur = s.top();s.pop();
        if(cur->lNode) s.push(cur->lNode);
        if(cur->rNode) s.push(cur->rNode);
        delete cur;
    }
    binTree = nullptr;
}

void Huffman::encoding(const string &str) {
    cout << "Will be encode message: " << str << "\n";

    map<char, int> map;

    for(auto c: str) {
        map[c]++;
    }

    priority_queue<Node*, vector<Node*>, Node> pq;
    for(auto& e: map) {
        pq.push(new Node(e.character, e.count));
    }

    while(pq.size() > 1) {
        Node* lNode = pq.top();
        pq.pop();
        Node* rNode = pq.top();
        pq.pop();

        Node* newNode = new Node(lNode, rNode);
        pq.push(newNode);
    }

    binTree = pq.top();
    pq.pop();

    _getCode(str);

    return;
}

void Huffman::_getCode(const string &str) {
    string code = "";
    map<char, string> m;

    stack<pair<Node*, string>> s;
    s.push({binTree, ""});

    while(!s.empty()) {
        Node* cur = s.top().first;
        string tmp = s.top().second;
        s.pop();

        if (cur->rNode != nullptr) s.push({cur->rNode, tmp + "1"});
        if (cur->lNode != nullptr) s.push({cur->lNode, tmp + "0"});
        if (cur->lNode == nullptr && cur->rNode == nullptr) {
            m[cur->ch] = tmp;
        }
    }

    for (const char& c: str) {
        code += m[c];
    }
    this->code = code;
    return;
}

std::string Huffman::decoding() const {
    if (binTree == nullptr) {
        cout << "message should be encoded before decoding!\n";
        return "";
    }

    string ret = "";

    const Node* cur = binTree;
    for(const char& c: code) {
        if (c == '0') cur = cur->lNode;
        else cur = cur->rNode;

        if (cur->lNode == nullptr && cur->rNode == nullptr) {
            ret += cur->ch;
            cur = binTree;
        }
    }

    return ret;
}

bool Node::operator()(const Node *lNode, const Node *rNode) const {
    return lNode->cnt > rNode->cnt;
}

string Huffman::getCode() const {
    if (code == "") {
        cout << "message should be encoded!\n";
    }
    return code;
}

