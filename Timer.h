#pragma once
#include <chrono>
#include <thread>
#include <list>

class Timer
{
private:
  static void thread_timer(int milliseconds, void(*callback)(void*), void* origin) 
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    (*callback)(origin);
  }
public:
  static void timer(int milliseconds, void(*callback)(void*), void* origin) 
  {
    std::thread chronometer = std::thread(Timer::thread_timer, milliseconds, callback, origin);
    chronometer.detach();
  }
};