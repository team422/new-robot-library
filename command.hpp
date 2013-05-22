#ifndef COMMAND_HPP_INCLUDED
#define COMMAND_HPP_INCLUDED

#include <vector>
#include <functional>
#include "subsystem.hpp"

class Command {
  public:
	Command();
	Command( std::function<void()> );

	void set_action( std::function<void()> );

	void requires( const Subsystem& );

	std::vector<Subsystem*> get_requirements();

	bool does_require( const Subsystem& );

	void set_interruptible( bool );

	bool get_interruptible();

	void operator()();
  private:
	std::function<void()> my_action;
	std::vector<Subsystem*> my_requirements;
	bool my_is_interruptible;
};

#endif // COMMAND_HPP_INCLUDED
