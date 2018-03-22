#include <bits/stdc++.h>

using namespace std;

#define MAXLEN 1000 // Per problem definition.

class charStack {
    private:
        int top;
        char a[MAXLEN];
    
    public:
        charStack() { top = -1; }
        bool push(char c);
        char pop(); // In this problem, we don't care about the returned currently returned item.
        char topValue(); // This is what we'll care about in this problem.
        int size() { return top + 1; }
};

bool charStack::push(char c) {
    if (top >= MAXLEN) {
        cout << "Stack overflow" << endl;
        return false;
    } else
        a[++top] = c;
    
    return true;
}

char charStack::pop() {
    char ret;
    
    if (top < 0) {
        cout << "Stack underflow" << endl;
        return '\0';
    } else
        ret = a[top--]; // We could overwrite with a known good but why bother? Let it be overwritten on the next push()
    
    return ret;
}

char charStack::topValue() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        return '\0';
    } else {
        return a[top];
    }
}

string isBalanced(string s) {
		char currentOpen = '\0';
    
    charStack theStack;
    
    for (auto c : s) {
        if ((currentOpen == '(' && c == ')') ||
            (currentOpen == '{' && c == '}') ||
            (currentOpen == '[' && c == ']') ||
            (currentOpen == ')' && c == '(') ||
            (currentOpen == '}' && c == '{') ||
            (currentOpen == ']' && c == '[')) {
            if (theStack.size() > 0) {
                theStack.pop();
            
                if (theStack.size() > 0)
                    currentOpen = theStack.topValue();
                else
                    currentOpen = '\0';
            }
            else
                currentOpen = '\0';
        } else {
					currentOpen = c;
					theStack.push(c);   				         
        }
    }

		if (theStack.size() > 0)
			return "NO";

    return "YES";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    return 0;
}
