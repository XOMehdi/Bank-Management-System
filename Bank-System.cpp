#include <iostream>
using namespace std;

class Serial
{ // storing serial no. of objects
private:
    string serial_no; // will store serial no of oobject in this data member
    string FirstString = "2022FAST0";
    string SecondString = "OOP";
    static int count; // static variable to show how many objects have been created
    string mid;       // non constant varible
public:
    Serial()
    { // default constructor
        count++;
        mid = to_string(count); // converting int count to string
        serial_no = FirstString + mid + SecondString;
    }

    string ShowSerialNo()
    { // function to show serial no
        cout << "I'am abject with Serial Number : " << serial_no << endl;
        return serial_no;
    }
};

int Serial::count = 0;

int main()
{
    Serial S1, S2, S3, S4, S5; // creating objects
    S1.ShowSerialNo();
    S2.ShowSerialNo();
    S3.ShowSerialNo();
    S4.ShowSerialNo();
    S5.ShowSerialNo();
    return 0;
}