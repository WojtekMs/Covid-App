#pragma once

#include "User.hpp"
#include "Shop.hpp"

enum class Age {
    LessThan18,
    From18To25,
    From26To59,
    MoreThan60,
    UNKNOWN,
};

class Customer : public User {
    Age age_{Age::UNKNOWN};

    public:
    void iAmInShop(const std::shared_ptr<Shop>& shop);
    void iFinishedShopping(const std::shared_ptr<Shop>& shop);
    Age getAge() const { return age_; }
};
