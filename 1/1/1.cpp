

#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;

};


class LogConsole :public LogCommand {
public:

    void print(const std::string& messege) override
    {
        std::cout << messege << std::endl;
    }
};


class LogFile :public LogConsole {
    std::string filename;
    std::fstream f;
public:
    LogFile(std::string fName) : filename(fName)
    {
        f.open(fName, std::fstream::in | std::fstream::out | std::fstream::app);
        if (!(f.is_open())) std::cout << "can't open file" << std::endl;
        else std::cout << "File opend"<< std::endl;
    }
    void print(const std::string& messege) override
    {
        f << messege << std::endl;
        f.close();
        std::cout << "file updated and closed" << std::endl;
    }
};

void print(LogCommand& L, std::string text)
{
    L.print(text);
}

int main()
{
    LogConsole LC;
    LogFile LF("example.txt");
    print(LC, "Data1");
    print(LF, "Data2");


}

