#ifndef NODEHUFFMANTREE_H
#define NODEHUFFMANTREE_H

#pragma once
#include <unordered_map>

class NodeHuffmanTree
{
public:
    NodeHuffmanTree();
    ~NodeHuffmanTree();

    char getCh()
    {
        return ch;
    }
    void setCh(char ch_c)
    {
        ch = ch_c;
    }
    int getFreq()
    {
        return freq;
    }
    void setFreq(int freq_c)
    {
        freq = freq_c;
    }
    NodeHuffmanTree *getLeft()
    {
        return left;
    }
    void setLeft(NodeHuffmanTree *left_c)
    {
        left = left_c;
    }
    NodeHuffmanTree *getRight()
    {
        return right;
    }
    void setRight(NodeHuffmanTree *right_c)
    {
        right = right_c;
    }

    // Función para asignar un nuevo nodo de árbol
    NodeHuffmanTree(char ch, int freq, NodeHuffmanTree *left, NodeHuffmanTree *right);
    bool isLeaf(NodeHuffmanTree *root);
    void encode(NodeHuffmanTree* root, string str, unordered_map<char, string> &huffmanCode);
    unordered_map<char, string> buildHuffmanTree( priority_queue<Caracteres> cac);

private:
    char ch;
    int freq;
    NodeHuffmanTree *left, *right;
};
bool operator<(const NodeHuffmanTree &c1, const NodeHuffmanTree &c2)
{
    NodeHuffmanTree aux1, aux2;
    aux1 = c1;
    aux2 = c2;
    return aux1.getFreq() < aux2.getFreq();
}
#endif