#pragma once
#include <iostream>
using namespace std;


class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node()
    {
        value = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


void putNodeToTail(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void display(Node* head)
{
    Node* temp;
    temp = head;

    cout << "All numbers: \n";
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n\n";
}


bool Check(Node*& head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        if (temp->next != nullptr)
        {
            if (temp->value < temp->next->value)
            {
                temp = temp->next;
                continue;
            }
            return false;
        }
        temp = temp->next;
    }
    return true;
}

string CheckDrop(Node*& head)
{
    if (Check(head))
    {
        return "The list is sorted by height.\n\n";
    }
    return "The list isn't sorted\n\n";
}



bool identical_Numbers(Node*& head)
{
    Node* temp = head;
    Node* temp2 = temp->next;

    while (temp != nullptr)
    {
        while (temp2 != nullptr)
        {

            if (temp2->value == temp->value)
            {
                return true;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
        if (temp->next != nullptr)
        {
            temp2 = temp->next;
            continue;
        }
        break;
    }
    return false;
}

string check_Ident_Nums(Node*& head)
{
    if (identical_Numbers(head))
    {
        return "There is pair of identical numbers\n\n\n";
    }
    return "There isn't any pair of identical numbers\n\n\n";
}



bool swapValues(Node*& head)
{
    if (head == nullptr)
    {
        return false;
    }

    Node* temp1 = head;

    int counter = 0;
    while (temp1 != nullptr)
    {
        counter++;
        temp1 = temp1->next;
    }
    if (counter == 1) { return false; }


    Node* temp = head;


    while (temp != nullptr)
    {
        if (temp->next != nullptr)
        {

            int tempValue = temp->value;
            temp->value = temp->next->value;
            temp->next->value = tempValue;

            if (temp->next->next == nullptr)
            {
                return true;
            }
            temp = temp->next->next;
            continue;
        }
        return true;
    }
}

string Swap(Node*& head)
{
    if (swapValues(head))
    {
        return "The values were swapping\n\n";
    }
    return "There is one value in your list\n\n";
}
