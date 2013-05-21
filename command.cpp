#include "command.hpp"
#include <algorithm>

Command::Command() {}

Command::Command( std::function<void()> action ) :
  my_action( action ) {}

void Command::set_action( std::function<void()> action ) {
	my_action = action;
}

void Command::requires( const Subsystem *subsystem ) {
	auto it = std::find( my_requirements.begin(), my_requirements.end(), subsystem );
	if( it == my_requirements.end() ) { // The subsystem is not already in the vector
		my_requirements.push_back( subsystem );
	}
}

std::vector<Subsystem*> Command::get_requirements() {
	return my_requirements;
}

void Command::operator()() {
	my_action();
}
