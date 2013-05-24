#include "command.hpp"
#include <algorithm>

Command::Command() :
  my_is_interruptible( true ) {}

Command::Command( std::function<void()> action ) :
  my_action( action ),
  my_is_interruptible( true ) {}

inline void Command::set_action( std::function<void()> action ) {
	my_action = action;
}

inline void Command::requires( const Subsystem &subsystem ) {
	my_requirements.insert( &subsystem )
}

inline std::unordered_set<Subsystem*> Command::get_requirements() {
	return my_requirements;
}

bool Command::does_require( const Subsystem subsystem ) {
	auto it = my_requirements.find( &subsystem );
	if( it != my_requirements.end() ) {
		return true;
	}
	else {
		return false;
	}
}

inline void Command::operator()() {
	my_action();
}
