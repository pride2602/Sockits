#include "Header.h"
#include <iostream>

using namespace std;

// Trie Node
struct Trie {
    Trie* arr[27] = { NULL };

    // Stores the index of the word
    // in the dictionary
    int idx;
};

// Root node of the Trie
Trie* root = new Trie();

// Function to insert the words in
// the Trie
void insert(string word, int i)
{
    // Temporary pointer to the root
    // node of the Trie
    Trie* temp = root;

    // Traverse through all the
    // characters of current word
    for (char ch : word) {

        // Make a Trie Node, if not
        // already present
        if (temp->arr[ch - 'a'] == NULL) {
            Trie* t = new Trie();
            temp->arr[ch - 'a'] = t;
        }

        temp = temp->arr[ch - 'a'];
        temp->idx = i;
    }
}

// Function to search the words in Trie
int search(string word)
{
    Trie* temp = root;

    // Traverse through all the
    // characters of current word
    for (char ch : word) {

        // If no valid Trie Node exists
        // for the current character
        // then there is no match
        if (temp->arr[ch - 'a'] == NULL)
            return -1;
        temp = temp->arr[ch - 'a'];
    }

    // Return the resultant index
    return temp->idx;
}

// Function to search for a word in
// the dictionary with the given
// prefix and suffix for each query
void findMatchingString(
    string words[], int n,
    vector<vector<string> > Q)
{
    string temp, t;

    // Insertion in the Trie
    for (int i = 0; i < n; i++) {

        // Form all the words of the
        // form suffix{word and insert
        // them in the trie
        temp = "{" + words[i];

        for (int j = words[i].size() - 1;
            j >= 0; j--) {
            t = words[i][j] + temp;
            temp = t;

            // Insert into Trie
            insert(t, i);
        }
    }

    // Traverse all the queries
    for (int i = 0; i < Q.size(); i++) {

        string prefix = Q[i][0];
        string suffix = Q[i][1];
        string temp = suffix + "{" + prefix;

        // Stores the index of
        // the required word
        int res;

        // Store the index of the
        // word in the dictionary
        res = search(temp);

        // In case of match, print
        // the corresponding string
        if (res != -1) {
            cout << words[res] << '\n';
        }

        // Otherwise, No match found
        else
            cout << "-1\n";
    }
}

// Driver Code
int main()
{
    string arr[]
        = { "apple", "app", "biscuit",
            "mouse", "orange", "bat",
            "microphone", "mine" };
    int N = 8;
    vector<vector<string> > Q = { { "o", "e" }, { "mo", "se" } };
    findMatchingString(arr, N, Q);

    return 0;
}