// https://practice.geeksforgeeks.org/problems/huffman-decoding-1/1

//{ Driver Code Starts
#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std;
map<char, string> codes;
map<char, int> freq;
struct MinHeapNode {
  char data;
  int freq;
  MinHeapNode *left, *right;

  MinHeapNode(char data, int freq) {
    left = right = NULL;
    this->data = data;
    this->freq = freq;
  }
};
struct compare {
  bool operator()(MinHeapNode* l, MinHeapNode* r) {
    return (l->freq > r->freq);
  }
};
void printCodes(struct MinHeapNode* root, string str) {
  if (!root)
    return;
  if (root->data != '$')
    cout << root->data << ": " << str << "\n";
  printCodes(root->left, str + "0");
  printCodes(root->right, str + "1");
}
void storeCodes(struct MinHeapNode* root, string str) {
  if (root == NULL)
    return;
  if (root->data != '$')
    codes[root->data] = str;
  storeCodes(root->left, str + "0");
  storeCodes(root->right, str + "1");
}

priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

void HuffmanCodes(int size) {
  struct MinHeapNode *left, *right, *top;
  for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
    minHeap.push(new MinHeapNode(v->first, v->second));
  while (minHeap.size() != 1) {
    left = minHeap.top();
    minHeap.pop();
    right = minHeap.top();
    minHeap.pop();
    top = new MinHeapNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    minHeap.push(top);
  }
  storeCodes(minHeap.top(), "");
}
void calcFreq(string str, int n) {
  for (int i = 0; i < str.size(); i++)
    freq[str[i]]++;
}
string decode_file(struct MinHeapNode* root, string s);
int main() {
  codes.clear();
  freq.clear();
  minHeap = priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare>();
  string str;
  cin >> str;
  string encodedString, decodedString;
  calcFreq(str, str.length());
  HuffmanCodes(str.length());
  /*cout << "Character With there Frequencies:\n";
  for (auto v=codes.begin(); v!=codes.end(); v++)
      cout << v->first <<' ' << v->second << endl;*/
  for (auto i : str)
    encodedString += codes[i];
  // cout <</* "\nEncoded Huffman data:\n" << */encodedString << endl;
  decodedString = decode_file(minHeap.top(), encodedString);
  cout << /* "\nDecoded Huffman Data:\n" << */ decodedString << endl;

  return 0;
}
// } Driver Code Ends

/*Complete the function below
Which contains 2 arguments
1) root of the tree formed while encoding
2) Encoded String*/
string decode_file(struct MinHeapNode* root, string s) {
  int i = 0;
  int size = s.length();
  string ans = "";
  struct MinHeapNode* curr = root;
  while (i < size) {
    if (s[i] == '0') {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
    if(curr->data!='$'){
      ans.push_back(curr->data);
      curr=root;
    }
    i++;
  }
  return ans;
}