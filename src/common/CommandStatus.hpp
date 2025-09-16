#pragma once

enum class CommandStatus : unsigned char
{
    PENDING,
    EXECUTING,
    COMPLETED,
    FAILED,
    CANCELLED,
    SCHEDULED

};