//
// Created by Arthur Lockman on 4/5/17.
//

#pragma once

#include "Command.h"
#include "Thread.h"
#include <list>
#include <iostream>
#include <map>
#include <mutex>

/**
 * Class to manange the various system commands. Commands injected into the CommandManager are run periodically until the command is done. Once the command is done, the command manager cleans up the command and removes it from the run queue.
 */
class CommandManager: public Thread {
public:
    /**
     * Creates the command manager object.
     */
    CommandManager();
    /**
     * Destroys the command manager object.
     */
    ~CommandManager();
    /**
     * Add a command to be run. Create your command, and then
     * pass a pointer to it in to this method. It will be run
     * along with all other scheduled commands.
     * @param command A pointer to a command object.
     * @return true if successful.
     */
    bool runCommand(Command *command);
    /**
     * Cancel a command. Pass in the pointer to the command you
     * want canceled, and it will be canceled and un-scheduled.
     * @param command A pointer to a command object.
     * @return true if successful.
     */
    bool cancel(Command* command);
    /**
     * Cancel all running commands.
     * @return true if successful.
     */
    bool cancelAll();
    /**
     * Threading run function
     * @return nil
     */
    void* run();
    /**
     * Re-join the thread and end command execution.
     * @return result of join
     */
    int join();
    /**
     * Re-join the thread and end command execution.
     * @return result of join
     */
    int kill();
    /**
     * Get how many commands are in flight in the command manager.
     * @return a long, the number of commands.
     */
    unsigned long inFlight();
private:
    //! List of commands
    std::list<Command*> m_commands;
    //! Map of commands to command flags
    std::map<Command*, int> m_command_flags;
    //! Mutex to keep data safe.
    std::mutex mtx;
};
