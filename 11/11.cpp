#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node of Huffman Tree
struct Node
{
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Compare nodes based on frequency
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

// Generate Huffman Codes
void generateCodes(Node *root, string code,
                   unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    // Leaf node
    if (root->left == nullptr && root->right == nullptr)
    {
        huffmanCode[root->data] = code;
        return;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Huffman Coding function
void huffmanCoding(string text)
{
    // Count frequency of each character
    unordered_map<char, int> freq;

    for (char ch : text)
        freq[ch]++;

    // Min Heap
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // Create a node for every character
    for (auto pair : freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node('\0',
                                 left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Root of Huffman Tree
    Node *root = pq.top();

    // Generate codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Display Huffman Codes
    cout << "\nHuffman Codes:\n";

    for (auto pair : huffmanCode)
    {
        cout << pair.first << " : "
             << pair.second << endl;
    }

    // Encode the text
    string encodedText = "";

    for (char ch : text)
    {
        encodedText += huffmanCode[ch];
    }

    cout << "\nOriginal Text:\n";
    cout << text << endl;

    cout << "\nEncoded Text:\n";
    cout << encodedText << endl;

    cout << "\nOriginal size: "
         << text.length() * 8 << " bits" << endl;

    cout << "Compressed size: "
         << encodedText.length() << " bits" << endl;
}

int main()
{
    string text;

    cout << "Enter the text: ";
    getline(cin, text);

    huffmanCoding(text);

    return 0;
}
