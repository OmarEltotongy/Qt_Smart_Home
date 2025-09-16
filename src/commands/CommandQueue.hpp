#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include <mutex>
#include <memory>
#include "src/common/CommandStatus.hpp"
#include "src/commands/Command.hpp"

class Command;
using namespace std;

class CommandQueue
{
private:
    queue<shared_ptr<Command>> pendingCommands;
    vector<shared_ptr<Command>> executeCommands;
    vector<shared_ptr<Command>> failedCommands;
    mutex queueMutex;
    bool isProcessing;
    int maxQueueSize;

public:
    CommandQueue() = default;
    ~CommandQueue() = default;

    bool enqueue(const shared_ptr<Command>& cmd);
    bool executeNext();
    bool undoLast();
    bool cancelCommand(const string& cmdID);
    void clearQueue();
    void pauseProcessing();
    void resumeProcessing();
    CommandStatus getQueueStatus();
    vector<shared_ptr<Command>> getExecutionHistory();
};
