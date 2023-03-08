#include "mbed.h"

DigitalIn mypin(BUTTON1);
DigitalOut Ledclock(LED1);
DigitalOut myled(LED2);
// main() runs in its own thread in the OS
int main()
{
    int syb = 0;
    while (true) {
        Ledclock = 1;
        if(syb==0){
            myled = 0;
        }
        else{
            syb--;
        }
        ThisThread::sleep_for(600ms);
        if(mypin.read() == 0){
            syb = 1;
        }
        ThisThread::sleep_for(1s);
        if((mypin.read() == 0) && (syb == 1)){
            syb = 3;
        }
        ThisThread::sleep_for(400ms); 
        
        Ledclock = 0;
        if(syb==0){
            myled = 0;
        }
        else{
            myled = 1;
            syb--;
        }
        ThisThread::sleep_for(2s); 
    }
   

}