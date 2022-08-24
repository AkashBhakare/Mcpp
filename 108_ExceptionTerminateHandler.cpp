// 108_ExceptionTerminateHandler.cpp : 
#include <cstdlib>
#include "iostream"
using namespace std;

/*
 * Understand the function
 * set_terminate()
 *
 */
void myHandler()
{
    cout << "Some unexpected error has occurred!\n";
    cout << "Please contact the developer at support@impetusits.in";
    cout << endl;
    exit(EXIT_FAILURE);
}

void foo(void) noexcept(true);

int main()
{
    //set the terminate handler
    set_terminate(myHandler);
    try
    {
        //        void (*fp)(void) = get_terminate() ;
        //        fp();
        cout << "calling foo() from main()\n";
        foo();
        cout << "back to try block in main()\n";
    }
    catch (const string& errMsg)
    {
        cerr << "Error Code:" << errMsg << "\n";
        cerr.flush();
    }

    //    throw invalid_argument("Wrong Place");
    cout << "inside main, but after try-catch!\n\n";

    set_terminate(0); //reset handler
    return 0;
}

void foo() noexcept(true)
{
    cout << "Inside foo()\n";
    //        throw string("Some Error has occurred!");
    throw 2.4F;
    return;
}