#include <bits/stdc++.h>
using namespace std;
void solve(string s)
{
    stack<string> st;
    string words = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
            words = words + s[i];
        else
        {
            st.push(words);
            words = "";
        }
    }
    st.push(words);
    while (!st.empty())
    {

        cout << st.top() << endl;
        st.pop();
    }
}
int main()
{

    string s = "hello what are you doing";
    solve(s);
}