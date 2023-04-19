//
// Created by 안진우 on 2023/04/19.
//

#ifndef COMPRESS_MANAGER_HUFFMAN_H
#define COMPRESS_MANAGER_HUFFMAN_H

#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

class Node {
public:
    Node(): lNode(nullptr), rNode(nullptr), cnt(0), ch(0) {}
    Node(char ch, int cnt): lNode(nullptr), rNode(nullptr), cnt(cnt), ch(ch) {}
    Node(Node* left, Node* right): lNode(left), rNode(right), cnt(left->cnt + right->cnt), ch(0) {}

    bool operator()(const Node* lNode, const Node* rNode) const;

    Node* lNode;
    Node* rNode;
    uint32_t cnt;
    char ch;
};

class Huffman {
private:
    Node* binTree;
    string code;

    void _getCode(const std::string& str);

public:
    Huffman(): binTree(nullptr), code("") {}
    ~Huffman();

    void encoding(const std::string& str);
    string getCode() const;
    string decoding() const;
};

#endif //COMPRESS_MANAGER_HUFFMAN_H