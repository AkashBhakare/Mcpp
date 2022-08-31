//116_ExceptionStackUnwinding

#include <stdexcept>
#include <iostream>
#include "error_handler.h"


void check_pointer(std::exception_ptr p) {
	if (p == nullptr)
		throw std::runtime_error("bad pointer");
	return;
}

void check_pointer(void const* p)
{
}

ErrorState handle_exception(std::exception_ptr ep) {

	try {
		check_pointer(ep);
		std::rethrow_exception(ep);
	}
	catch (std::bad_alloc const&) {
		return ErrorState::no_memory;
	}
	catch (std::range_error const&) {
		std::cout << "value_out_of_range\n";
		return ErrorState::value_out_of_range;
	}
	catch (std::invalid_argument const& e) {
		std::cout << e.what();
		// for simplicity we assume all bad 
		// arguments are bad pointers
		return ErrorState::bad_pointer;
	}
	catch (...) {

		return ErrorState::unknown_error;
	}
	return ErrorState::okay;
}