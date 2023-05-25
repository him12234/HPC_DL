#include <iostream>
#include <stdlib.h>
#include <queue>
#include <cmath> // for fabs
using namespace std;

class node
{
public:
    node *left, *right;
    int data;
};

class Breadthfs
{
public:
    node *insert(node *, int);
    void bfs(node *, const vector<int> &);
};

node *insert(node *root, int data)
{
    if (!root)
    {
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = new node;
            temp->left->left = NULL;
            temp->left->right = NULL;
            temp->left->data = data;
            return root;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = new node;
            temp->right->left = NULL;
            temp->right->right = NULL;
            temp->right->data = data;
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

void bfs(node *head, const vector<int> &expectedOutput)
{
    queue<node *> q;
    q.push(head);

    int qSize;
    int nodesVisited = 0;
    int correctNodes = 0;

    while (!q.empty())
    {
        qSize = q.size();

        for (int i = 0; i < qSize; i++)
        {
            node *currNode = q.front();
            q.pop();
            cout << "\t" << currNode->data;

            nodesVisited++;
            if (nodesVisited <= expectedOutput.size() && currNode->data == expectedOutput[nodesVisited - 1])
            {
                correctNodes++;
            }

            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }
    }

    double accuracy = (correctNodes / static_cast<double>(expectedOutput.size())) * 100;
    cout << "\nAccuracy: " << accuracy << "% (Correct: " << correctNodes << "/" << expectedOutput.size() << ")" << endl;
}

int main()
{
    node *root = NULL;
    int data;
    char ans;
    vector<int> expectedOutput;

    do
    {
        cout << "\nEnter data = ";
        cin >> data;

        root = insert(root, data);
        expectedOutput.push_back(data);

        cout << "Do you want to insert one more node? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    cout << "\nBFS traversal: ";
    bfs(root, expectedOutput);

    return 0;
}