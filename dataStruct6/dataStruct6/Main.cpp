#include <iostream>
#include "Calculator.h"

using namespace std;

int main(int argc, char const *argv[]) {
    Calculator J = Calculator();

    //cout << J.run("1+(1+(1+3)*2)*3")<<endl;
    //cout << J.run("2^3^4") << endl;
    //cout << J.run("12%5") << endl;
    //cout << J.run("-12") << endl;
    //cout << J.run("-1.3*3") << endl;
    //cout << J.run("-1.3*-3") << endl;
    //cout << J.run("23+(-32)*7/abs(-2^3)") << endl;
    //cout << J.run("abs(2 - abs(1-9))") << endl;

    cout << J.translate("(1+2*3)/4-5/(6-7)");
    
    return 0;
}
