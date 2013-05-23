#ifndef SCHEDULER_HPP_INCLUDED_422_MTD_
#define SCHEDULER_HPP_INCLUDED_422_MTD_

#include <unordered_set>
#include "command.hpp"
#include "command_sequence.hpp"
#include "button.hpp"
#include "subsystem.hpp"

class Scheduler {
  public:
	bool schedule( Command& );
	bool schedule( CommandSequence& )

	bool repeat( Command& );
	bool repeat( CommandSequence& );
	bool repeat( Command&, int );
	bool repeat( CommandSequence&, int );

	void bind( Button&, Command& );
	void bind( Button&, CommandSequence& );

	void repeat_while_held( Button&, Command& );
	void repeat_while_held( Button&, CommandSequence& );

  private:
	std::unordered_set<Subsystem*> my_active_subsystems;
};

#endif // SCHEDULER_HPP_INCLUDED_422_MTD_
