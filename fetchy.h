#ifndef FETCHY_H_
#define FETCHY_H_

#include <string>

namespace fetchy {
class Fetchy {
public:
  Fetchy();

private:
  std::string GetDistro();
  std::string GetArchitechture();
  std::string GetDeviceName();
  std::string GetCPU();
  std::string GetGPU();
  std::string GetMemory();
  std::string GetKernel();
  std::string GetDiskCapacity(bool home_partition_exists);
  std::string GetColorTag(int color, std::string icon);
  std::string BetweenDelimiter(std::string str, char delimiter);

  void Output();
};
} // namespace fetchy

#endif
