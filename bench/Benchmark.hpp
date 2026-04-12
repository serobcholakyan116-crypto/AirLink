#pragma once
#include <functional>
#include <string>

class Benchmark {
public:
    static void run(const std::string& name, const std::function<void()>& fn, int iterations);
};
