#include "Customer.hpp"

void Customer::iAmInShop(const std::shared_ptr<Shop>& shop)
{
    if (!shop) {
        return;
    }
    shop->addCustomer(this);
}

void Customer::iFinishedShopping(const std::shared_ptr<Shop>& shop)
{
    if (!shop) {
        return;
    }
    shop->removeCustomer(this);
}
