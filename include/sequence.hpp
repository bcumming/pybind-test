#pragma once

#include <memory>
#include <iostream>
#include <cstdint>

class sequence {
public:
    virtual float front() const = 0;
    virtual void pop() = 0;

    virtual ~sequence() = default;
};

class regular_sequence: public sequence {
public:
    regular_sequence(float init, float step):
        init_(init), step_(step), count_(0)
    {}

    float front() const override {
        return init_ + step_*count_;
    }

    void pop() override {
        ++count_;
    }

private:
    float init_;
    float step_;
    std::uint64_t count_;
};

using sequence_ptr = std::unique_ptr<sequence>;

template <typename T, typename... Args>
sequence_ptr make_sequence(Args&&... args) {
    return sequence_ptr(new T(std::forward<Args>(args)...));
}

inline
sequence_ptr make_regular_sequence(float init, float step) {
    return make_sequence<regular_sequence>(init, step);
}

inline void popper(sequence* seq, unsigned n) {
    while (n--) seq->pop();
}
