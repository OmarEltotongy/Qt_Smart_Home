#ifndef __COMMANDSTATUS_H__
#define __COMMANDSTATUS_H__

enum class CommandStatus : unsigned char
{
    PENDING,
    EXECUTING,
    COMPLETED,
    FAILED,
    CANCELLED,
    SCHEDULED

};
#endif // __COMMANDSTATUS_H__