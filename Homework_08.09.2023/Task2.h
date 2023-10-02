#pragma once
#include <iostream>
#include <vector>
using namespace std;



class Node {
public:
    int value;
    Node* next;

    Node()
    {
        value = 0;
        next = nullptr;
    }

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};


void putNodeToTail(Node*& head, int value)
{
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;
}

void display(Node* head)
{

    if (head == NULL)
    {
        cout << "Stack is empty";
        return;
    }

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << "\n\n";
}



void NegativeStack(Node* head1, Node* head2, Node*& newStack)
{
    while (head1 != nullptr)
    {
        if (head1->value < 0)
        {
            putNodeToTail(newStack, head1->value);
        }
        head1 = head1->next;
    }

    while (head2 != nullptr)
    {
        if (head2->value < 0)
        {
            putNodeToTail(newStack, head2->value);
        }
        head2 = head2->next;
    }

    if (newStack != nullptr)
    {
        cout << "Negative values: ";
        display(newStack);
        return;
    }
    cout << "There are no negative values in two stacks!\n\n";
    return;
}



void Inversion(Node*& head)
{
    vector<int> tempStack;

    while (head != nullptr)
    {
        tempStack.push_back(head->value);
        head = head->next;
    }
    for (int i = 0; i < tempStack.size(); i++)
    {
        putNodeToTail(head, tempStack[i]);
    }
    cout << "After inversion: ";
}



bool equal(Node* head1, Node* head2)
{
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->value == head2->value)
        {
            head1 = head1->next;
            head2 = head2->next;
            continue;
        }
        return false;
    }
    return true;
}
void isEqual(Node*& head1, Node*& head2)
{
    Node* head3 = nullptr;
    if (equal(head1, head2) == NULL)
    {
        cout << "The stacks aren't equal!\n\n";

        NegativeStack(head1, head2, head3);
        return;
    }
    cout << "The stacks are equal!\n\n";
    Inversion(head2); // If the stacks are equal, make inversion of second stack
    display(head2); // Display inversed stack
    cout << "\n\n";
    return;
}