#include "Test.hpp"

void testingPhoneNumberConstructor()
{
	//PhoneNumber ph1("+167-6567876-");
}

void testGet()
{
	PhoneNumber ph("+1-22-333");

	ASSERT_EQUAL(ph.GetCountryCode(), "1");

	ASSERT_EQUAL(ph.GetCityCode(), "22");

	ASSERT_EQUAL(ph.GetLocalNumber(), "333");

	ASSERT_EQUAL(ph.GetInternationalNumber(), "+1-22-333");
}

void runTests()
{
	MyUnitTest::TestRunner tr;

	RUN_TEST(tr, testingPhoneNumberConstructor);

	RUN_TEST(tr, testGet);

	/*tr.RunTest(testingPhoneNumberConstructor, "testingPhoneNumberConstructor");

	tr.RunTest(testGet, "testGet");*/
}