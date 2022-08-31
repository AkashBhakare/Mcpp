#pragma once
#include <stdexcept>
enum class ErrorState {
    okay,
    no_memory,
    value_out_of_range,
    bad_pointer,
    unknown_error
};

void check_pointer(void const* p);
ErrorState handle_exception(std::exception_ptr ep);