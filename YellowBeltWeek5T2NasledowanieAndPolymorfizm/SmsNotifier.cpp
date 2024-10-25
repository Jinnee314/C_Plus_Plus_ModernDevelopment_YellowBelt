#include "SmsNotifier.hpp"

SmsNotifier::SmsNotifier(const std::string& str) : telNum(str)
{}

void SmsNotifier::Notify(const std::string& message)
{
	SendSms(this->telNum, message);
}