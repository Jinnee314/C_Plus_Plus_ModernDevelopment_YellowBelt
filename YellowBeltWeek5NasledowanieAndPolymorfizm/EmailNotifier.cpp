#include "EmailNotifier.hpp"

EmailNotifier::EmailNotifier(const std::string& str) : email(str)
{}

void EmailNotifier::Notify(const std::string& message)
{
	SendSms(this->email, message);
}
