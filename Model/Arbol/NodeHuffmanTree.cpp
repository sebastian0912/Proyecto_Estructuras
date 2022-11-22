#include "NodeHuffmanTree.h"
#include "../Caracteres.h"
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

#define EMPTY_STRING ""

using namespace std;
NodeHuffmanTree::NodeHuffmanTree() {}

NodeHuffmanTree::NodeHuffmanTree(char ch, int freq, NodeHuffmanTree *left, NodeHuffmanTree *right)
{
    this->ch = ch;
    this->freq = freq;
    this->left = left;
    this->right = right;
}

NodeHuffmanTree::~NodeHuffmanTree() {}

NodeHuffmanTree *root = nullptr;

bool isLeaf(NodeHuffmanTree *root)
{
    NodeHuffmanTree *aux = root;
    return aux->getLeft() == NULL && aux->getRight() == NULL;
}

void encode(NodeHuffmanTree *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
    {
        return;
    }

    // encontrado un nodo hoja
    if (isLeaf(root))
    {
        huffmanCode[root->getCh()] = (str != EMPTY_STRING) ? str : "1";
    }

    encode(root->getLeft(), str + "0", huffmanCode);
    encode(root->getRight(), str + "1", huffmanCode);
}

struct comp
{
    bool operator()(const NodeHuffmanTree *l, const NodeHuffmanTree *r) const
    {
        // el elemento de mayor prioridad tiene la menor frecuencia
        NodeHuffmanTree aux, aux2;
        aux = *l;
        aux2 = *r;
        return aux.getFreq() > aux2.getFreq();
    }
};

unordered_map<char, string> buildHuffmanTree(priority_queue<Caracteres> cac)
{
    int sum = 0;
    // Crear una cola de prioridad para almacenar nodos en vivo del árbol de Huffman
    priority_queue<NodeHuffmanTree *, vector<NodeHuffmanTree *>, comp> pq;

    // llena la cola de prioridad con los caracteres
    while (!cac.empty())
    {
        Caracteres c = cac.top();
        pq.push(new NodeHuffmanTree(c.getCaracter(), c.getFrecuencia(), nullptr, nullptr));
        cac.pop();
    }

    // imprimir la cola de prioridad
    /*while (!pq.empty())
    {
        NodeHuffmanTree aux;
        aux = *pq.top();
        cout << aux.getCh() << " " << aux.getFreq() << endl;
        pq.pop();
    }*/

    // iterar hasta que haya más de un nodo en la cola de prioridad
    while (pq.size() != 1)
    {
        // elimina los dos nodos de menor frecuencia de la cola de prioridad
        NodeHuffmanTree *left = pq.top();
        pq.pop();
        NodeHuffmanTree *right = pq.top();
        pq.pop();

        // crea un nuevo nodo interno con frecuencia igual a la suma de las frecuencias de los dos nodos eliminados
        // cout << "left: " << left->getCh() << " " << left->getFreq() << endl;
        // cout << "right: " << right->getCh() << " " << right->getFreq() << endl;
        int sum = left->getFreq() + right->getFreq();
        // cout << "Suma: " << sum << endl;
        pq.push(new NodeHuffmanTree('\0', sum, left, right));
        // cout << "------------------"<< endl;
    }
    // `root` stores pointer to the root of Huffman Tree
    root = pq.top();

    // Traverse the Huffman Tree and store Huffman Codes
    // in a map. Also, print them
    unordered_map<char, string> huffmanCode;
    encode(root, EMPTY_STRING, huffmanCode);

    /*cout << "Huffman Codes are:\n" << endl;
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << endl;
    }*/

    return huffmanCode;
}

void decode(NodeHuffmanTree *root, int &index, string str)
{
    if (root == nullptr)
    {
        return;
    }

    // encontrado un nodo hoja
    if (isLeaf(root))
    {
        if (root->getCh() == '/')
        {
            cout << "\n";
        }
        else
        {
            cout << root->getCh();
        }
        return;
    }

    index++;

    if (str[index] == '0')
    {
        decode(root->getLeft(), index, str);
    }
    else
    {
        decode(root->getRight(), index, str);
    }
}

void decodificarHuffman(string str)
{
    if (isLeaf(root))
    {
        int freq = root->getFreq();
        // Special case: For input like a, aa, aaa, etc.
        while (freq--)
        {
            cout << root->getCh();
        }
    }
    else
    {
        // Traverse the Huffman Tree again and this time,
        // decode the encoded string
        int index = -1;
        while (index < (int)str.size() - 1)
        {
            decode(root, index, str);
        }
    }
    cout << endl;
}