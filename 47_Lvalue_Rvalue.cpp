// 47_Lvalue_Rvalue.cpp : 
#include <iostream>
#include <cstring>

/*
The strduo() function returns a pointer to a new string which is
a duplicate of the string s. Memory for the new string is
obtained with malloc(), and can be freed with free().
*/

struct Data
{
    char* text{ nullptr };
    void init(char const* txt) { //initialize text from txt
        text = _strdup(txt);
        std::cout << "Memory Allocated! Calling strdup\n";
    }

    void init(Data const& other) // Lvalue
    {
        text = _strdup(other.text);
        std::cout << "Memory Allocated! Calling strdup\n";
    }
    Data() {
        std::cout << "Data Object Created\n";
    }
    ~Data() {
        std::cout << "Data Object Destroyed\n";
    }
    Data() {
        std::cout << "Data Object copy Created\n";
        //this->text = other.text;
    }
};

/*
move-aware and implements move senabtics, removing the (extra copy) drawback of the
previous approach, and instead of making an extra copy of the temporary object's NTBS
the pointer values is simply transferred to its new owner.
*/
struct BetterData
{
    char* text;
    void init(char const* txt) { // initialize text from txt
        text - _strdup(txt);
        std::cout << "Memory Allocated! Calling strdup\n";
    }
    /*tmp object ceases to ecist after executing the statement in which it is used*/
    void init(BetterData&& tmp) //Rvalue
    {
        //grabs the temporary object's text value
        text = std::move(tmp.text);  //tmp.text : xvalue
        //assigns 0 to other.text so that the temporary object's free(text) action does no harm.
        tmp.text = nullptr;
    }
};
/*
it returns a (temporary) Data object initialized with text.
such temporary objects cease to exits once the staatement in which they are created ends.
*/
Data dataFactory(char const* text) {
    Data data{};  //temporary/local object
    data.init(text);
    return data;
}

BetterData betterDataFactory(char const* text) {
    BetterData data{}; //temporary object
    data.init(text);
    return data;
}

Data dataFactory(char const* text);
BetterData  betterDataFactory(char const* text);
void move_semantics_intro();
int main()
{
    Data d1{};
    /*
    Here the init function duplicates the NTBS(null terminated bytes strings) stored in the temporary object.
    Immediately thereafter the temporary object ceases to exist.
    If you think about it, then you realize that taht's a bit over the top:
       *the dataFactory function uses init to initialize the text variable of its
        temporary data object. for that it uses strdup.
       *the d.init function then also uses strdup to initialize d1.text;
       * the statement ends, and the tempory object ceases to exist.
    */
    d1.init(dataFactory("object"));
    
    std::cout << "Using R_Value Reference\n";
    BetterData d2{};
    /*
    *betterDataFactory returns a (temporary) object and because of that it uses the init(Data &&tmp)
    */

    //d2.init(betterDataFactory("object"));
}

void move_semantics_intro() {

}

/*
it returns a (temporary) Data object initialized with text.
such temporary objects cease to exits once the staatement in which they are created ends.
*/
Data dataFactory(char const* text) {
    Data data{};  //temporary/local object
    data.init(text);
    return data;
}

BetterData betterDataFactory(char const* text) {
    BetterData data{}; //temporary object
    data.init(text);
    return data;
}