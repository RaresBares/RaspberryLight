//
// Created by rasah_s2z0ncs on 04.03.2020.
//


#include <wiringPi.h>
#include <thread>
#include <iostream>
#include "leucht.h"

struct pruf {

     leucht leuchtthis;

    pruf(const leucht &leucht) : leuchtthis(leuchtthis) {}

    void operator()()   {


        while (true) {
            pinMode(21, INPUT);
            pinMode(20, INPUT);


            int i = digitalRead(21);
            int o = digitalRead(20);
            bool t = true;

            std::this_thread::sleep_for(std::chrono::seconds(1));

            if (i == 1) {
                std::cout << "+10" << "\n";
                if( leuchtthis.hz + 10 >=500 ){
                    leuchtthis.hz +=10;
                }
                t = false;
            }
            if (o == 1 && t) {
                std::cout << "-10"<< "\n";
                if( leuchtthis.hz - 10 <=0 ){
                    leuchtthis.hz -=10;
                }

                std::cout << "jetzt: " << leuchtthis.hz << "\n";
            }

        }
    }
};


