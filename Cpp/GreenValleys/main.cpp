#include "GreenValleys.h"

int main() {
    CC cc("./data.txt");
    string str = cc.toString();
    cout << str << endl;
    cout << "Number of valleys: " << cc.count() << endl;
    cout << "Deepest point is: " << cc.getDeepestPoint() << endl;
    return 0;
}