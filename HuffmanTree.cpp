#include<bits/stdc++.h>
using namespace std;

struct HuffmanNode
{
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}

    struct Compare
    {
        bool operator()(HuffmanNode* l, HuffmanNode* r)
        {
            return l->freq > r->freq;
        }
    };
};

void generateHuffmanCode(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCode)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateHuffmanCode(root->left, code + '0', huffmanCode);
    generateHuffmanCode(root->right, code + '1', huffmanCode);
}

HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& freqMap)
{
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::Compare> minHeap;

    for (const auto& pair : freqMap)
        minHeap.push(new HuffmanNode(pair.first, pair.second));

    while (minHeap.size() > 1)
    {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}

void printHuffmanCode(const unordered_map<char, string>& huffmanCode)
{
    vector<pair<char, string>> sortedHuffmanCode(huffmanCode.begin(), huffmanCode.end());
    sort(sortedHuffmanCode.begin(), sortedHuffmanCode.end());

    for (const auto& pair : sortedHuffmanCode)
        cout << pair.first << ": " << pair.second << endl;
}

void deleteHuffmanTree(HuffmanNode* root)
{
    if (!root) return;
    deleteHuffmanTree(root->left);
    deleteHuffmanTree(root->right);
    delete root;
}

int main()
{
    string text;
    getline(cin, text);

    unordered_map<char, int> freqMap;
    for (char c : text)
        freqMap[tolower(c)]++;

    HuffmanNode* root = buildHuffmanTree(freqMap);

    unordered_map<char, string> huffmanCode;
    generateHuffmanCode(root, "", huffmanCode);

    printHuffmanCode(huffmanCode);

    deleteHuffmanTree(root);

    return 0;
}