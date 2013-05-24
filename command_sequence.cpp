#include "command_sequence.hpp"

CommandSequence::CommandSequence() :
  my_current_command( my_sequence.begin() ) {}

void CommandSequence::add( const Command &command ) {
	std::pair< Command*, bool > next_command(
	  &command,
	  my_next_command_interruptible
	);

	my_sequence.push_back( next_command );
}

void CommandSequence::add( const CommandSequence &command_sequence ) {
	my_sequence.insert( my_sequence.end(),
	  command_sequence.my_sequence.begin(),
	  command_sequence.my_sequence.end() );
}

inline void CommandSequence::begin_uninterruptible() {
	my_next_command_interruptible = false;
}

inline void CommandSequence::end_uninterruptible() {
	my_next_command_interruptible = true;
}

inline bool CommandSequence::is_finished() {
	return ( my_current_command == my_sequence.end() );
}

void CommandSequence::run_next_command() {
	if( my_current_command == my_sequence.end() ) {
		return;
	}
	else {
		(*(my_current_command->first))();
		++my_current_command;
	}
}

inline bool CommandSequence::can_interrupt() {
	return my_current_command->first;
}
