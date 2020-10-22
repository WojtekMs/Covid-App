#include "UserDataBase.hpp"

void UserDataBase::addUser(const std::shared_ptr<User>& user)
{
    userMap_.emplace(std::make_pair(user->getLogin(), user));
}
void UserDataBase::removeUser(const std::shared_ptr<User>& user)
{
    userMap_.erase(user->getLogin());
}
