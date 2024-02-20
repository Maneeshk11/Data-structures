
# LEFTIST TREES

### Can create max and min biased leftist trees;

### Stucture of the leftist tree :
    * isMin_ : a boolean value that specifies whether the tree is min biased or max biased.
    * root_ : it is a TreeNode that is the root of the leftist tree.

### Structure of a node :
    * T data : the data to be stored in the node.
    * int sdist : It is the shortest path from the node to an external node.
    * left and right children pointers.

### Methods implemented:
    * MeldTrees() : Join 2 trees so that the leftist tree properties always hold.
    * Initialize() : Creates a new leftist tree from an input vector or an array.
    * getRoot() : Returns the data in the root node of the leftist tree.
    * put() : Adds a node to the leftist tree by performing a meld operation.
    * removeMin() : Remove the root of the min leftist tree (which is the minimum value). Followed by a meld of left and right subtrees of the root.
    * removeMax() : Remove the root of the max leftist tree (which is the max value). Followed by a meld of left and right subtrees of the root.

Reference: 
    1. http://web.onda.com.br/abveiga/capitulo5-ingles.pdf