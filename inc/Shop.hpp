#pragma once

#include "Location.hpp"

#include <memory>
#include <string>
#include <unordered_map>

class Customer;
class ShopOwner;
class Shop
{
   public:
    struct AdditionalInfo {
        std::string hoursOpened_{};
        double cargoAvailability_{};
        std::string availablePaymentMethods_{};
    };

   private:
    std::string name_{};
    Location location_{};
    AdditionalInfo additionalInfo_{};
    int currentClientsCount_{};
    int maxClientsCount_{};
    int totalClientsToday_{};
    std::unordered_map<Customer*, size_t> clients_{};
  

   public:
    Shop() = default;
    explicit Shop(const Location& location);

    const std::string& getName() const { return name_; }
    int getClientsCount() const { return currentClientsCount_; }
    int getMaxClientsCount() const { return maxClientsCount_; }
    const Location& getLocation() const { return location_; }
    const AdditionalInfo& getAdditionalInfo() const { return additionalInfo_; }

    void addCustomer(Customer* customer, size_t count = 1);
    void removeCustomer(Customer* customer);
    void setAdditionalInfo(const AdditionalInfo& info);
};
