#pragma once

#include "User.hpp"
#include "Shop.hpp"
#include <memory>

class ShopOwner :public User {
    std::string NIP{};
    std::shared_ptr<Shop> shop_{};
    public:
    ShopOwner() = default;
    explicit ShopOwner(const std::shared_ptr<Shop>& shop);
    void editAdditionalInfo(const Shop::AdditionalInfo& info);
};
