#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    stack<char> st;
    int l = str.size();
    int flag = 1;
    for (int i = 0; i < l; ++i)
    {
        switch (str[i])
        {
        case '(':
            st.push(str[i]);
            break;
        case '[':
            st.push(str[i]);
            break;
        case '{':
            st.push(str[i]);
            break;
        case ')':
            if (st.top() == '(')
                st.pop();
            else
                flag = 0;
            break;
        case ']':
            if (st.top() == '[')
                st.pop();
            else
                flag = 0;
            break;
        case '}':
            if (st.top() == '{')
                st.pop();
            else
                flag = 0;
            break;
        }
    }
    if (!flag)
    {
        cout << "不匹配" << endl;
    }
    else
    {
        if (!st.empty())
        {
            cout << "不匹配" << endl;
        }
        else
        {
            cout << "匹配" << endl;
        }
    }
    return 0;
}
