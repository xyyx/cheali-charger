#include "Timer.h"
#include "TimerOne.h"
#include "Hardware.h"
#include "Monitor.h"
#include "Buzzer.h"
#include "Screen.h"

static void callback() {
    static uint8_t slowInterval = TIMER_SLOW_INTERRUPT_INTERVAL;
    timer.doInterrupt();
    monitor.doInterrupt();
    buzzer.doInterrupt();
    if(--slowInterval == 0){
        slowInterval = TIMER_SLOW_INTERRUPT_INTERVAL;
        smps.doSlowInterrupt();
        discharger.doSlowInterrupt();
        screen.doSlowInterrupt();
    }
}


Timer timer;


Timer::Timer() : interrupts_(0) {
}

void Timer::init()
{
    Timer1.initialize(INTERRUPT_PERIOD_MICROSECONDS);         // initialize timer1, and set a 1/2 second period
    Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}

void Timer::doInterrupt()
{
    interrupts_++;
}
uint32_t Timer::getMiliseconds() const
{
    uint32_t retu = interrupts_;
#if INTERRUPT_PERIOD_MICROSECONDS == 512
    retu *= (INTERRUPT_PERIOD_MICROSECONDS/8);
    retu /= (1000/8);
#else
#warning "INTERRUPT_PERIOD_MICROSECONDS != 512"
    retu *= INTERRUPT_PERIOD_MICROSECONDS;
    retu /= 1000;
#endif

    return retu;
}

void Timer::delay(uint16_t ms) const
{
    uint32_t end;
    end = getMiliseconds() + ms;

    while(getMiliseconds() < end) {};
}

