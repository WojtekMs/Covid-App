#pragma once

#include "User.hpp"

#include <memory>
#include <string>
#include <unordered_map>

using UserMap = std::unordered_map<std::string, std::shared_ptr<User>>;

class UserDataBase
{
    UserMap userMap_{};

   public:
    void addUser(const std::shared_ptr<User>& user);
    void removeUser(const std::shared_ptr<User>& user);
    const UserMap& getUsers() const { return userMap_; }
};
