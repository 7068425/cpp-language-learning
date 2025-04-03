// outfile.cpp -- writing to a file
#include <iostream>
#include <fstream>                  // for file I/O
 
int main()
{
    using namespace std;
 
    char automobile[50];
    int year;
    double a_price;
    double d_price;
 
    ofstream outFile;               // create object for output
    outFile.open("carinfo.txt");    // associate with a file
 
    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;
 
// display information on screen with cout
 
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;
 
// now do exact same things using outFile instead of cout
 
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;
    
    outFile.close();                // done with file
    // cin.get();
    // cin.get();
    return 0;
}

/*该程序演示了简单的文件输入，将输入的信息显示到屏幕上并写入到文件中
其中头文件fstream定义了一个用来处理输出的ofstream
其中ofstream outFile用来声明一个ofstream对象，outFile.open("carinfo.txt")用来将刚刚声明的对象与文件关联起来
防止数字太大，系统会以科学表示法的方式打印，所以使用一个流操作符 fixed，它表示浮点输出应该以固定点或小数点表示法显示
cout.precision(val)：在输出的时候，设定输出值以新的浮点数精度值显示，即小数点后保留val位
cout.setf(ios::showpoint) 在c++中是为了保留原有的类型精度（四舍五入原则）*/

