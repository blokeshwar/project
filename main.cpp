#include <bits/stdc++.h>
using namespace std;

string current_url = "";

stack<string> forward_stack;

stack<string> backward_stack;

stack<string> history;

void visit_new_url(string url)
{
    if (current_url != "")
    {
        backward_stack.push(
                current_url);
    }

    current_url = url;
    history.push(current_url);
    forward_stack = stack<string>();
}

int forward()
{
    if (forward_stack.empty())
    {
        cout << "Forward of current Url is Not Available\n";
        return 0;
    }
    else
    {
        backward_stack.push(current_url);

        current_url = forward_stack.top();
        history.push(current_url);

        forward_stack.pop();
        return 1;
    }
}

int backward()
{
    if (backward_stack.empty())
    {
        cout << "Backward of current Url is Not Available\n";
        return 0;
    }
    else
    {
        forward_stack.push(current_url);

        current_url = backward_stack.top();
        history.push(current_url);

        backward_stack.pop();
        return 1;
    }
}

void printCurrentState()
{
    cout << endl;
    stack<string> temp1, temp2;

    temp1 = backward_stack;
    while (!temp1.empty())
    {
        temp2.push(temp1.top());
        temp1.pop();
    }
    while (!temp2.empty())
    {
        cout << temp2.top() << endl;
        temp2.pop();
    }

    cout << current_url << " << Current URL" << endl;

    temp1 = forward_stack;
    while (!temp1.empty())
    {
        cout << temp1.top() << endl;
        temp1.pop();
    }
}

void printHistory()
{
    stack<string> temp = history;
    cout<<"\nHistory is:"<<endl;
    while(!temp.empty())
    {
        cout << temp.top() << endl;
        temp.pop();
    }
}

int main()
{
    string choice;
    while (1)
    {
        cout << endl << "1. Current State  2. Go back  3. Go forward  4. History  5. Exit" << endl;
        cout << current_url << " > ";
        cin >> choice;

        if (choice == "1")
        {
            printCurrentState();
        }
        else if (choice == "2")
        {
            backward();
        }
        else if (choice == "3")
        {
            forward();
        }
        else if (choice == "4")
        {
            printHistory();
        }
        else if (choice == "5")
        {
            return 0;
        }
        else
        {
            visit_new_url(choice);
        }
    }
}