// Demonstrate the copy constructor and assignment operator

#include <iostream>
#include <string>
#include "person.h"

int main(int argc, const char *argv[])
{
    person noname;
    cout << "name: " << noname.getName() << " age: " << noname.getAge() << endl;

    person tom("Tom", 20 );
    person sameName = tom;
    noname = tom;

    cout << "name: " << noname.getName() << " age: " << noname.getAge() << endl;
    cout << "name: " << tom.getName() << " age: " << tom.getAge() << endl;
    cout << "name: " << sameName.getName() << " age: " << sameName.getAge() << endl;

    sameName.setName("Bruce");
    sameName.setAge(55);
    noname = tom = sameName;

    cout << "name: " << noname.getName() << " age: " << noname.getAge() << endl;
    cout << "name: " << tom.getName() << " age: " << tom.getAge() << endl;
    cout << "name: " << sameName.getName() << " age: " << sameName.getAge() << endl;

	system("pause");
    return 0;
}
