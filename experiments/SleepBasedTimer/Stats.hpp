/**
 * @file Stats.hpp File to calculate statistics for different processes. Uses a circular buffer of a given size to prevent dynamic allocations to the buffer.
 */

#pragma once

#include <chrono>
#include <iostream>
#include <limits>

struct StatPoint
{
  double executionTimeMs;
};

class StatTracker
{
public:
  StatTracker(unsigned int bufferSize)
  {
    _bufferSize = bufferSize;
    _arr = new StatPoint[bufferSize];
    _totalElements = 0;
    _sum = 0;
  }

  // copies the struct. Might not be high perf.
  void Add(StatPoint stat)
  {
    auto tmp = _arr[index];

    _arr[index] = stat;
    index = (index + 1) % _bufferSize;

    _sum += stat.executionTimeMs;
    
    if (_totalElements < _bufferSize)
    {
      _totalElements++;
    }
    else
    {
      _sum -= tmp.executionTimeMs;
    }
  }

  double GetAverageDurationMs()
  {
    return _sum / _totalElements;
  }

  double GetMaxVal()
  {
    double maxVal = 0.0;
    for (int i = 0; i < _totalElements; i++)
    {
      if (_arr[i].executionTimeMs > maxVal)
      {
        maxVal = _arr[i].executionTimeMs;  
      }
    }
    return maxVal;
  }

  double GetMinVal()
  {
    double minVal = std::numeric_limits<double>::max();
    for (int i = 0; i < _totalElements; i++)
    {
      if (_arr[i].executionTimeMs < minVal)
      {
        minVal = _arr[i].executionTimeMs;  
      }
    }
    return minVal;
  }

private:
  StatPoint *_arr;
  double _averageDuration = 0.0;
  int index = 0;
  double _sum;
  int _bufferSize;
  int _totalElements;
};