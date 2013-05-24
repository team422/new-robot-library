#ifndef COMMAND_HPP_INCLUDED_422_MTD_
#define COMMAND_HPP_INCLUDED_422_MTD_

#include <unordered_set>
#include <functional>
#include "subsystem.hpp"

class Command {
  public:
	Command();
	Command( std::function<void()> );

	void set_action( std::function<void()> );

	void requires( const Subsystem& );

	std::unordered_set<Subsystem*> get_requirements();

	bool does_require( const Subsystem& );

	void operator()();
  private:
	std::function<void()> my_action;
	std::unordered_set<Subsystem*> my_requirements;
};

#endif // COMMAND_HPP_INCLUDED_422_MTD_
