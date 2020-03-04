#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <iostream>



// P0-P7 is 0-7 works through pins 29
// see pin connections

int hz = 120;
struct leucht{






    void operator()() const {






        while (true) {
            std::cout << "jetzt: " << hz << "\n";
            digitalWrite(4, 1);
            digitalWrite(5, 0);
            digitalWrite(6, 0);
            digitalWrite(13, 0);
            delay(hz);
            std::this_thread::sleep_for(     std::chrono::nanoseconds(hz));
            digitalWrite(4, 1);
            digitalWrite(5, 1);
            digitalWrite(6, 0);
            digitalWrite(13, 0);
            delay(hz);
            std::this_thread::sleep_for(     std::chrono::nanoseconds(hz));
            digitalWrite(4, 1);
            digitalWrite(5, 1);
            digitalWrite(6, 1);
            digitalWrite(13, 0);
            delay(hz);
            std::this_thread::sleep_for(     std::chrono::nanoseconds(hz));
            digitalWrite(4, 1);
            digitalWrite(5, 1);
            digitalWrite(6, 1);
            digitalWrite(13, 1);
            delay(hz);
            std::this_thread::sleep_for(     std::chrono::nanoseconds(hz));
            digitalWrite(4, 0);
            digitalWrite(5, 1);
            digitalWrite(6, 1);
            digitalWrite(13, 1);
            delay(hz);
            std::this_thread::sleep_for(     std::chrono::nanoseconds(hz));
            digitalWrite(4, 0);
            digitalWrite(5, 0);
            digitalWrite(6, 1);
            digitalWrite(13, 1);
            delay(hz);
            std::this_thread::sleep_for(     std::chrono::nanoseconds(hz));
            digitalWrite(4, 0);
            digitalWrite(5, 0);
            digitalWrite(6, 0);
            digitalWrite(13, 1);

            delay(hz);
            std::this_thread::sleep_for(     std::chrono::nanoseconds(hz));
            digitalWrite(4, 0);
            digitalWrite(5, 0);
            digitalWrite(6, 0);
            digitalWrite(13, 0);
            delay(hz);

            
            std::this_thread::sleep_for(     std::chrono::nanoseconds(hz));
        }
    }
};




int main() {
    if (wiringPiSetup() == -1 || wiringPiSetupGpio() == -1)
        exit(1);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(21, INPUT);
    pinMode(20, INPUT);
    leucht leucht{};
    std::cout << "jetzt: " << hz << "\n";
    std::thread thread{leucht};

    std::cout << "jetzt: " << hz << "\n";








    while (true) {

        int& a = hz;

        int i = digitalRead(21);
        int o = digitalRead(20);
        bool t = true;

        std::this_thread::sleep_for(std::chrono::nanoseconds (20));

        if (i == 1) {
            std::cout << "+10" << "\n";


                a +=50;

            t = false;
            std::this_thread::sleep_for(std::chrono::seconds (1));

        }
        if (o == 1 && t) {
            std::cout << "-10"<< "\n";

                a -=50;

            std::this_thread::sleep_for(std::chrono::seconds (1));

        }
        std::cout << "jetzt: " << hz << "\n";

    }




    return 0 ;
}