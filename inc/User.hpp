#pragma once

#include "Location.hpp"

#include <memory>
#include <string>
class User
{
    std::string login_{};
    std::string password_{};
    std::string email_{};
    Location location_{};

   public:
    User() = default;
    explicit User(const Location& location);
    const std::string& getLogin() const { return login_; }
    const Location& getLocation() const { return location_; }
};
