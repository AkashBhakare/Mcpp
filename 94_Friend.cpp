// 94_Friend.cpp : 

/*
* Friend function :
* Member function of a one class is made friend of another class
*/


#include "iostream"


// Forward Declaration
class Sample;

/*Declare the class first and define it later */
class Other {
private:
    int private_data;

public:
    void updateSample(Sample& ref);
    void bar();
};

class Sample {
    //member function other class declared as friend to the class
    friend void Other::updateSample(Sample&);
private:
    int m_pri;
protected:
    int m_prot;
public:

    Sample(void) : m_pri(9), m_prot(7) {
    }

    void printPrivate(void) const {
        std::cout << "Private member : " << m_pri << std::endl;
    }

    void printProtected()const {
        std::cout << "Protected member : " << m_prot << std::endl;
    }
}; //end of class

/* Definition of members of class Other */
void Other::updateSample(Sample& ref) {
    ref.m_pri++; //Sample Class private member is accessed
    ref.m_prot++;//Sample Class protected member is accessed
}

void Other::bar() {
    Sample obj;

    //    cout << "Inside A::bar " << obj.m_pri << endl;
    //    cout << "Inside A::bar " << obj.m_prot << endl;
}

int main() {
    Sample sampleObject;
    sampleObject.printPrivate();
    sampleObject.printProtected();

    Other otherObject;
    otherObject.updateSample(sampleObject);
    sampleObject.printPrivate();
    sampleObject.printProtected();
    return 0;
}