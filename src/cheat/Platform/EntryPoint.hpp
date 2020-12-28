#ifndef ENTRYPOINT_HPP
#define ENTRYPOINT_HPP

#include <mutex>
#include <condition_variable>

extern std::mutex m;
extern std::condition_variable cv;
extern std::unique_lock<std::mutex> lk;

int main();

void Unload(int nExitCode);

#endif