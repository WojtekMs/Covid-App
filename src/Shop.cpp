#include "Shop.hpp"
#include "Location.hpp"
#include "Customer.hpp"

#include <numeric>
#include <iostream>

Shop::Shop(const Location& location) : location_(location) {}

void Shop::addCustomer(Customer* customer, size_t count) {
    if (clients_.find(customer) == clients_.end()) {
        currentClientsCount_ += count;
        totalClientsToday_ += count;
    }
    clients_.insert(std::make_pair(customer, count));
}

void Shop::removeCustomer(Customer* customer) {
    if (clients_.find(customer) != clients_.end()) {
        currentClientsCount_ -= clients_[customer];
    }
    clients_.erase(customer);
}

void Shop::setAdditionalInfo(const AdditionalInfo& info) {
    additionalInfo_ = info;
}
