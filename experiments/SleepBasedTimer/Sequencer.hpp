
/**
 * This is a C++ version of a sequencer using sleeps rather than ISR timers. 
 * The sequencer should run on the main core and the RTCore should run the  
 **/
#pragma once

#include <cstdint>
#include <vector>
#include <memory>

class Service
{
public:
  template<typename T>
  Service(T&& doService, uint8_t period, uint8_t priority, uint8_t affinity);
};

class Sequencer
{
public:
  Sequencer(uint8_t priority, uint8_t affinity);
  
  template<typename... Args>
  void addService(Args&&... args);
  void startServices();
  void stopServices();

private:
  std::vector<std::unique_ptr<Service>> services;
};