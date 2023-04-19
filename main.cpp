//
// Created by 안진우 on 2023/04/19.
//
#include <iostream>
#include "huffman/huffman.h"

using namespace std;
void testHuffman();


int main() {
    int choice;
    while(true) {
        printf("\033[2J");
        cout << "Enter the number for the algorithm test you want\n"
                "(1) Huffman\n";

        cin >> choice;
        if (choice == 1) {
            cout << "Huffman Test\n";
            testHuffman();
        } else {
            cout << "Not implemented algorithm number.\n";
        }
    }
    return 0;
}

void testHuffman(){
    Huffman h;
    string str;

    cout << "Enter your message: ";
    cin >> str;
    h.encoding(str);
    string encrypted = h.getCode();

    cout << "You encrypt message: " << encrypted << "\n";

}