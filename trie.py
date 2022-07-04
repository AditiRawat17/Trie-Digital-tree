# define alphabet size (26 characters for a – z)
CHAR_SIZE = 26
 
 
# A class to store a Trie node
class Trie:
    # Constructor
    def __init__(self):
        self.isLeaf = False
        self.children = [None] * CHAR_SIZE
 
 
    # Iterative function to insert a string into a Trie
    def insert(self, key):
        print('Inserting…', key)
 
        # start from the root node
        curr = self
 
        # do for each character of the key
        for i in range(len(key)):
            index = ord(key[i]) - ord('a')
            # create a new node if the path does not exist
            if curr.children[index] is None:
                curr.children[index] = Trie()
            # go to the next node
            curr = curr.children[index]
 
        # mark the current node as a leaf
        curr.isLeaf = True
 
 
    # Iterative function to search a key in a Trie. It returns True
    # if the key is found in the Trie; otherwise, it returns False
    def search(self, key):
        print('Searching', key, end=': ')
        curr = self
 
        # do for each character of the key
        for c in key:
            # go to the next node
            index = ord(c) - ord('a')
            curr = curr.children[index]
            # if the string is invalid (reached end of a path in the Trie)
            if curr is None:
                return False
 
        # return true if the current node is a leaf node, and we have reached
        # the end of the string
        return curr.isLeaf
 
 
if __name__ == '__main__':
 
    # construct a node
    head = Trie()
 
    head.insert('xyz')
    print(head.search('xyz'))
 
