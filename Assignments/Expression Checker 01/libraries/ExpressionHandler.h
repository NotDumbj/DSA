#include <vector>
#include <string>

using std::string;

class ExpressionHandler{
public:
    void loadData();
    bool checkExpression(int lineNumber);
    bool isValid(string expression);
    void displayData();
private:
    std::vector<string> data;
};