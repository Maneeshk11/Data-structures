#include <bits/stdc++.h>
#include "TournamentTree.h"

using namespace std;

int main() {
    vector<int> arr = {4, 3, 6, 8, 1, 5, 7, 3, 2, 6, 9, 4, 5, 2, 5, 8};
    
    cout << "winner tree operation: "<< endl;
    TournamentTree<int>::WinnerTree winnertree(arr, true);
    cout << "get winner: " << winnertree.getWinner() << endl;
    winnertree.replaceWinnerAndReplay(6);
    cout << "replace winner with 6: " << winnertree.getWinner() << endl;

    cout << "loser tree operation: "<< endl;
    TournamentTree<int>::LoserTree losertree(arr, true);
    cout << "get winner: " << losertree.getWinner() << endl;
    cout << "replace winner with 9: " << endl;
    losertree.replaceWinnerAndReplay(9);
    cout << "new winner: " << losertree.getWinner() << endl;
    
    TournamentTree<int>::WinnerTree tree(arr, true);
    vector<int> sortedArray = tree.generateSortedArray();
    cout << "generate sorted array: ";
    for (int i=0; i<sortedArray.size(); i++) {
        cout << sortedArray[i] << " ";
    }
    cout << endl <<  "tree winner: " << tree.getWinner();
    return 0;
}