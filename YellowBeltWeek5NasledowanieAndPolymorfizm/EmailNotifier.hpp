#pragma once
#include "INotifier.hpp"

class EmailNotifier :
    public INotifier
{
    std::string email = "";
public:
    EmailNotifier(const std::string& e);

    void Notify(const std::string& message) override;
};

