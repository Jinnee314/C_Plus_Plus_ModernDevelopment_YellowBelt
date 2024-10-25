#include "MyUnitTestFreimwork.hpp"

#include <iostream>

class Person {
private:
    // приватные поля
public:
    void ChangeFirstName(int year, const std::string& first_name) 
    {
        // добавить факт изменения имени на first_name в год year
    }
    void ChangeLastName(int year, const std::string& last_name) 
    {
        // добавить факт изменения фамилии на last_name в год year
    }
    std::string GetFullName(int year) 
    {
        // получить имя и фамилию по состоянию на конец года year
    }
};

void TestChangeLastNameFirstName()
{
    Person p;

    p.ChangeLastName(2000, "Puchkina");
    p.ChangeFirstName(2005, "Polina");

    MyUnitTest::AssertEqual(p.GetFullName(1999), "Incognito", "LastFirst Incognito");
    MyUnitTest::AssertEqual(p.GetFullName(2001), "Puchkina with unknown first name");
    MyUnitTest::AssertEqual(p.GetFullName(2006), "Polina Puchkina");
}

void TestChangeFirstNameLastName()
{
    Person p;
   
    p.ChangeFirstName(2000, "Polina");
    p.ChangeLastName(2005, "Puchkina");
    
    MyUnitTest::AssertEqual(p.GetFullName(1999), "Incognito", "FirstLast Incognito");
    MyUnitTest::AssertEqual(p.GetFullName(2000), "Polina with unknown last name", "FirstLast Polina 2000");
    MyUnitTest::AssertEqual(p.GetFullName(2002), "Polina with unknown last name", "FirstLast Polina 2002");
    MyUnitTest::AssertEqual(p.GetFullName(2006), "Polina Puchkina", "FirstLast Polina Puchkina");

    p.ChangeFirstName(2003, "Alina");
    MyUnitTest::AssertEqual(p.GetFullName(2002), "Polina with unknown last name", "FirstLast Polina");
    MyUnitTest::AssertEqual(p.GetFullName(2004), "Alina with unknown last name", "FirstLast Alina");
    MyUnitTest::AssertEqual(p.GetFullName(2006), "Alina Puchkina", "FirstLast Alina Puchkina");

    p.ChangeFirstName(2003, "Kate");
    MyUnitTest::AssertEqual(p.GetFullName(2004), "Alina with unknown last name", "FirstLast Alina");
    MyUnitTest::AssertEqual(p.GetFullName(2006), "Alina Puchkina", "FirstLast Alina Puchkina");

    p.ChangeLastName(2003, "Kort");
    MyUnitTest::AssertEqual(p.GetFullName(2000), "Polina with unknown last name", "FirstLast Polina");
    MyUnitTest::AssertEqual(p.GetFullName(2004), "Alina Kort", "FirstLast Alina Kort");
    MyUnitTest::AssertEqual(p.GetFullName(2006), "Alina Puchkina", "FirstLast Alina Puchkina");
}

void TestAll()
{
    MyUnitTest::TestRunner tr;

    
}

int main()
{


	return 0;
}