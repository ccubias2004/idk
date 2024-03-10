#include<iostream>
#include<string>
#include<vector>
#include <iomanip>

template <typename T> 
class Item {
public:
    T name;
    T expiration;
    T category;
    int quantity;
    Item(T n, T e, T c, int q) {
        name = n;
        expiration = e;
        category = c;
        quantity = q;
    }
};

template<typename T> 
class Inventory {
private:
    std::vector<Item<T>> items;
public:
    void addNewItem(Item<T> newItem) {
        for (const auto& item : items) {
            if (item.name == newItem.name) {
                std::cout << "Item is already present in inventory" << std::endl;
                return;
            }
        }
        items.push_back(newItem);
        std::cout << "Added item: " << newItem.name << std::endl;
    }

    void increaseQuantity(T itemName, int quantity) {
        for (auto& item : items) {
            if (item.name == itemName) {
                item.quantity += quantity;
                std::cout << "Quantity of " << itemName << " has increased by " << quantity << ". Now at " << item.quantity << "." << std::endl;
                return;
            }
        }
        throw "Item not found.";
    }

    void updateItem(T itemName, T expiration, T category, int quantity) {
        for (auto& item : items) {
            if (item.name == itemName) {
                item.expiration = expiration;
                item.category = category;
                item.quantity = quantity;
                std::cout << "Updated item: " << itemName << std::endl;
                return;
            }
        }
        throw "Item not found.";
    }

    void removeItem(T itemName) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->name == itemName) {
                items.erase(it);
                std::cout << "Removed item: " << itemName << std::endl;
                return;
            }
        }
        throw "Item not found.";
    }

    void Total() {
        std::cout << "Total number of items in inventory: " << items.size() << std::endl;
    }

    void searchItem(T itemName) {
        for (const auto& item : items) {
            if (item.name == itemName) {
                std::cout << "Query for " << itemName << "." << std::endl;
                std::cout << "Item = " << item.name << "." << std::endl;
                std::cout << "Expiration Date = " << item.expiration << "." << std::endl;
                std::cout << "Category = " << item.category << "." << std::endl;
                std::cout << "Quantity = " << item.quantity << "." << std::endl;
                return;
            }
        }
        throw "Item not found.";
    }

    void displayItems() {
        std::cout << "-------Inventory-------" << std::endl;
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Expiration" << std::setw(15) << "Quantity" << std::setw(10) << "Category" << std::endl;
        for (const auto& item : items) {
            std::cout << std::left << std::setw(20) << item.name << std::setw(15) << item.expiration << std::setw(15) << item.quantity << std::setw(15) << item.category << std::endl;
        }
    }
};

template<typename T> 
class Appointment {
public: 
    T c_name;
    T ap_date;
    T ap_time;
    T CWID;
    Appointment(T n, T d, T t, T cw) {
        c_name = n;
        ap_date = d;
        ap_time = t;
        CWID = cw; 
    }
};

template<typename T> 
class AppointmentSystem {
private:
    std::vector<Appointment<T>> ap;
public:
    void schedule(Appointment<T> newAppointment) {
        for (const auto& appointment : ap) {
            if (appointment.CWID == newAppointment.CWID) {
                std::cout << "You have already scheduled an appointment!!!" << std::endl;
                return;
            }
        }
        ap.push_back(newAppointment);
        std::cout << newAppointment.CWID << ", your appointment has been scheduled." << std::endl;
    }

    void cancelAppointment(T CWID) {
        for (auto it = ap.begin(); it != ap.end(); ++it) {
            if (it->CWID == CWID) {
                std::cout << "Appointment for CWID " << CWID << " has been cancelled." << std::endl;
                ap.erase(it);
                return;
            }
        }
        std::cout << "No appointment found for CWID " << CWID << "." << std::endl;
    }

    void Total_appointments(T date, T time) {
        int count = 0;
        for (const auto& appointment : ap) {
            if (appointment.ap_date == date && appointment.ap_time == time) {
                count++;
            }
        }
        std::cout << "There are " << count << " total appointments on " << date << ", " << time << "." << std::endl;
    }

    void display() {
        std::cout << "-------Appointments-------" << std::endl;
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Date" << std::setw(15) << "Time" << std::setw(15) << "CWID" << std::endl;
        for (const auto& appointment : ap) {
            std::cout << std::left << std::setw(20) << appointment.c_name << std::setw(15) << appointment.ap_date << std::setw(15) << appointment.ap_time << std::setw(15) << appointment.CWID << std::endl;
        }
    }
};

int main() {
    Inventory<std::string> i1;
    Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    Item<std::string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    i1.displayItems();
    i1.updateItem("Milk","09/24/2023","Regular",3);
    i1.displayItems();
    i1.increaseQuantity("Cerels",10);
    i1.displayItems();
    try {
        i1.removeItem("bread");
    } catch(const char* msg) {
        std::cout << "Could not remove bread. " << msg << std::endl;
    }
    i1.displayItems();
    i1.updateItem("Cerels","09/27/2023","Regular",4);
    i1.displayItems();
    i1.removeItem("Milk");
    i1.displayItems();
    i1.Total();
    try {
        i1.searchItem("Cerels");
    } catch(const char* msg) {
        std::cout << msg << std::endl;
    }
     try {
        i1.updateItem("Cerels", "09/27/2023", "Regular", 4);
    } catch(const char* msg) {
        std::cout << msg << std::endl;
    }

    AppointmentSystem<std::string> a1;
    Appointment<std::string> A1("John Bob","09/12/2023","9:30 AM","889456723");
    a1.schedule(A1);
    Appointment<std::string> A2("Jim Lee","09/12/2023","10:30 AM","883476923");
    a1.schedule(A2);
    Appointment<std::string> A3("Chris Lynn","09/12/2023","12:00 PM","879455714");
    a1.schedule(A3);
    Appointment<std::string> A4("Arnav Shah","09/12/2023","12:00 PM","879459583");
    a1.schedule(A4);
    a1.display();
    a1.Total_appointments("09/12/2023","12:00 PM");
    a1.cancelAppointment("879459583");
    a1.display();
    a1.Total_appointments("09/12/2023","12:00 PM");

    return 0;
}