#ifndef COMMAND_SEQUENCE_HPP_INCLUDED_422_MTD_
#define COMMAND_SEQUENCE_HPP_INCLUDED_422_MTD_

#include <initializer_list>
#include <vector>
#include <utility>
#include "command.hpp"

class CommandSequence {
  public:
	CommandSequence();
	void add( const Command& );
	void add( const CommandSequence& );
	void begin_uninterruptible();
	void end_uninterruptible();
	bool is_finished();
	void run_next_command();
	bool can_interrupt();
  private:
	std::vector< std::pair< Command*, bool > > my_sequence;

	std::vector<
	  std::pair< Command*, bool >
	>::const_iterator my_current_command;

	bool my_next_command_interruptible;
};

#endif // COMMAND_SEQUENCE_HPP_INCLUDED_422_MTD_
