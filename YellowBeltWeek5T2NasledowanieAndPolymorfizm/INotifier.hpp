#pragma once
#include <string>

class INotifier
{
public:
	virtual void Notify(const std::string& str) = 0;
};

void SendSms(const std::string& number, const std::string& message);

void SendEmail(const std::string& email, const std::string& message);