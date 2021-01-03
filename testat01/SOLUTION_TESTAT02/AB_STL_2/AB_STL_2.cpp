// AB_STL_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MySmartPointer.h"

#include <memory>
#include <string>
#include <chrono>
#include <vector>


#define SMARTPOINTER
#define SHAREDPOINTER
#define RAWPOINTER

/*
// DEBUG
Raw pointer : 8.76e-05 Seconds.
Shared pointer : 5.65e-05 Seconds.
SmartPointer : 3.36e-05 Seconds.

// RELEASE
Raw pointer: 3.5e-06 Seconds.
std::shared_ptr: 8.1e-06 Seconds.
SmartPointer: 8e-06 Seconds.
*/

int main() {
    constexpr int n = 10000000;
    using Clock = std::chrono::system_clock;
    using s_t = std::chrono::duration<float>;

#ifdef RAWPOINTER
    {
        int n = 10;
        Clock::time_point start = Clock::now();
        {
            std::vector<int*> v;
            for (int i = 0; i < n; i++) {
                v.push_back(new int(i));
            }
            for (int i = 0; i < n; i++) {
                *v[i] = *v[i] * *v[i];
            }
        }
        Clock::duration d = Clock::now() - start;
        std::cout << "Raw pointer: " << std::chrono::duration_cast<s_t>(d).count() << " Seconds." << std::endl;
    }
#endif // RAWPOINTER

#ifdef SHAREDPOINTER
    {
        int n = 10;
        Clock::time_point start = Clock::now();
        {
            std::vector<std::shared_ptr<int>> v;
            for (int i = 0; i < n; i++) {
                v.push_back(std::make_shared<int>(i));
            }
            for (int i = 0; i < n; i++) {
                *v[i] = *v[i] * *v[i];
            }
        }
        Clock::duration d = Clock::now() - start;
        std::cout << "std::shared_ptr: " << std::chrono::duration_cast<s_t>(d).count() << " Seconds." << std::endl;
    }
#endif // SHAREDPOINTER


#ifdef SMARTPOINTER
    {
        int n = 10;
        Clock::time_point start = Clock::now();
        {
            std::vector<SmartPointer<int>> v;
            for (int i = 0; i < n; i++) {
                v.push_back(SmartPointer<int>{new int{ i }});
            }
            for (int i = 0; i < n; i++) {
                *v[i] = *v[i] * *v[i];
            }
        }
        Clock::duration d = Clock::now() - start;
        std::cout << "SmartPointer: " << std::chrono::duration_cast<s_t>(d).count() << " Seconds." << std::endl;
    }
#endif // SMARTPOINTER



    /*
    int* a = new int{ 10 };

    SmartPointer<int> sp00{ a };
    std::cout << "sp00 Unique = " << std::boolalpha << sp00.IsUnique() << std::endl;
    SmartPointer<int> sp01{ sp00 };

    std::cout << "sp00 Unique = " << std::boolalpha << sp00.IsUnique() << std::endl;
    std::cout << "sp01 Unique = " << std::boolalpha << sp01.IsUnique() << std::endl;


    {
        std::string hello = "Hello";
        std::shared_ptr<std::string> std_sp00 = std::make_shared<std::string>(hello);
        std::shared_ptr<std::string> std_sp01 = std::make_shared<std::string>(hello);

        std::cout << "std_sp00.use_count() = " << std_sp00.use_count() << std::endl;
        std::cout << "std_sp01.use_count() = " << std_sp01.use_count() << std::endl;

        std::cout << "std_sp00.IsUnique() = " << std::boolalpha << std_sp00.unique() << std::endl;
        std::cout << "std_sp01.IsUnique() = " << std::boolalpha << std_sp01.unique() << std::endl;

        std::shared_ptr<std::string> std_sp02{ std_sp00 };
        std::cout << "std_sp00.use_count() = " << std_sp00.use_count() << std::endl;
        std::cout << "std_sp02.use_count() = " << std_sp02.use_count() << std::endl;
    }
    */


    // std::cout << "sp1 Unique = " << std::boolalpha << sp1.IsUnique() << std::endl;
    /*
    SmartPointer<int> sp2{ a }; // <-- Why is 'm_targetManager NULL?
    std::cout << "sp1 Unique = " << std::boolalpha << sp1.IsUnique() << std::endl;

    SmartPointer<int> sp3{ sp1 };

    std::cout << "sp1 Unique = " << std::boolalpha << sp1.IsUnique() << std::endl;
    std::cout << "sp3 Unique = " << std::boolalpha << sp3.IsUnique() << std::endl;
    */
}
