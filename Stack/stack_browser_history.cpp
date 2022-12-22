#include<bits/stdc++.h>
using namespace std;

class BrowserHistory {
    private:
    stack<string> history;
    stack<string> future;

    public:

    BrowserHistory(string homepage)
    {
        visit(homepage);
    }

    void visit(string url)
    {
        history.push(url);
        future = stack<string>();
    }

    string back(int steps)
    {
        while(! history.empty() && steps-- > 0 )
        {
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }

    string forward(int steps)
    {
        while(! future.empty() && steps-- > 0)
        {
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }
};

int main()
{
    BrowserHistory b ("facebook.com");
    b.visit("pune.com");
    cout<<"Back : "<<b.back(1)<<endl;
    b.visit("abc.com");
    b.visit("xyz.com");
    b.visit("LMN.com");
    cout<<"Back : "<<b.back(2)<<endl;
    cout<<"Forward : "<<b.forward(2)<<endl;
    return 0;
}