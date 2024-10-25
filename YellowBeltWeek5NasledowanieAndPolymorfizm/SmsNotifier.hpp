#pragma once
#include "INotifier.hpp"

class SmsNotifier :
    public INotifier
{
    std::string telNum = "";
public:
    SmsNotifier(const std::string& str);

    void Notify(const std::string& message) override;
};

