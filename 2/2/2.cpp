




#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::move;

class observer {
public:
    virtual void onWarning(const std::string& message) {
        cout << message << endl;
    }
    virtual void onError(const std::string& message) { cout << message << endl; }
    virtual void onFatalError(const std::string& message) { cout << message << endl; }
};


class observed {
    vector<observer*> obj;
public:
    void warning(string message)const
    {
        for (auto m : obj)
        {
            m->onWarning(message);
        }
    }

    void error(string message)const
    {
        for (auto m : obj)
        {
            m->onError(message);
        }
    }

    void fatalError(string message)const
    {
        for (auto m : obj)
        {
            m->onFatalError(message);
        }
    }

    void addObserver(observer* obs)
    {
        obj.push_back(obs);
    }

};


int main()
{
    
    observer* ov;
    ov = new observer;
    observer* od;
    od = new observer;

    observed ob;
    ob.addObserver(ov);
    ob.addObserver(od);

    ob.warning("warning text");
    ob.error("error text");
    ob.fatalError("fatal error text");

}

