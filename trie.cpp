#include <bits/stdc++.h>
using namespace std;
const int ALPHA_SIZE = 26;

struct Trie 
{
   struct Trie *child[ALPHA_SIZE];
   bool endofstring; 
};
struct Trie *createNode(void) 
{
   struct Trie *tNode = new Trie;
   tNode->endofstring = false;
   for (int i = 0; i < ALPHA_SIZE; i++)
      tNode->child[i] = NULL;
   return tNode;
}
void insert(struct Trie *root, string key)
{
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) 
   {
      int index = key[i] - 'A';
      if (!curr->child[index])
         curr->child[index] = createNode();
         curr = curr->child[index];
   }
   curr->endofstring= true; //last node as leaf
}
bool search(struct Trie *root, string key) 
{ 
  
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) 
   {
      int index = key[i] - 'A';
      if (!curr->child[index])
         return false;
      curr = curr->child[index];
   }
   return (curr != NULL && curr->endofstring);
}
bool isEmpty(Trie* root) {
   for (int i = 0; i < ALPHA_SIZE; i++)
   if (root->child[i])
   return false;
   return true;
}
Trie* deletion(Trie* root, string key, int depth = 0)
{
   
   if (!root)
   return NULL;
   if (depth == key.size()) { 
      if (root->endofstring)
         root->endofstring = false; 
      if (isEmpty(root)) {
         delete (root);
         root = NULL;
      }
   return root;
   }
   
   int index = key[depth] - 'A';
   root->child[index] =
   deletion(root->child[index], key, depth + 1); 
   if (isEmpty(root) && root->endofstring == false)
   { 
      delete (root);
      root = NULL;
   }
   return root;
}
int main() {
   string inputs[] = {"HELLOWORLD","HI","BYE", "THE","THENA"}; 
   int n = sizeof(inputs)/sizeof(inputs[0]);
   struct Trie *root = createNode();
   for (int i = 0; i < n; i++)
   insert(root, inputs[i]);
   search(root, "HELLOWORLD")? cout << "Key is Found\n" :
   cout << "Key is not Found\n";
   search(root, "HE")? cout << "Key is Found\n" :
   cout << "Key is not Found\n";
   deletion(root, "THEN")? cout << "Key is deleted\n" :
   cout << "Key is not Deleted\n";
   return 0;
}
