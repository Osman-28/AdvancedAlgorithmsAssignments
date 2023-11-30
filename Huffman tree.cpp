#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int freq) : data(c), frequency(freq), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->frequency > right->frequency;
    }
};

HuffmanNode* buildHuffmanTree(const string& S, const vector<int>& f) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

   for (int i = 0; i < S.size(); ++i) {
        minHeap.push(new HuffmanNode(S[i], f[i]));
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

     return minHeap.top();
}

void printHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        cout << "  " << root->data << " : " << code << endl;
        huffmanCodes[root->data] = code;
    }

    printHuffmanCodes(root->left, code + "0", huffmanCodes);
    printHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};

    HuffmanNode* root = buildHuffmanTree(S, f);

    unordered_map<char, string> huffmanCodes;
    cout << "Huffman codes will be:" << endl;
    printHuffmanCodes(root, "", huffmanCodes);

    return 0;
}
