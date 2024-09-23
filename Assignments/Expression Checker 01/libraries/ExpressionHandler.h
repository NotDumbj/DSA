#include <map>
#include <string>

using std::string;

class ExpressionHandler{
public:
    ExpressionHandler();
    bool checkExpression(int lineNumber);
    bool isValid(string expression);
    void displayData();
private:
    std::map<int, string> data;
    void loadData();
};