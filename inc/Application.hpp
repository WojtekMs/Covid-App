#pragma once

#include "Location.hpp"
#include "ShopDataBase.hpp"
#include "UserDataBase.hpp"

#include <limits>
#include <memory>
#include <utility>

class Application
{
    std::unique_ptr<ShopDataBase> shops_{std::make_unique<ShopDataBase>()};
    std::unique_ptr<UserDataBase> users_{std::make_unique<UserDataBase>()};

   public:
    Application() = default;
    Application(std::unique_ptr<ShopDataBase>&& shops, std::unique_ptr<UserDataBase>&& users);
    const std::shared_ptr<Shop> getNearestShop(const Location& location) const;
    const std::shared_ptr<Shop>& getShop(const Location& location) const;
};
