#pragma once

namespace GLP
{
    enum debugErrorLevel: unsigned char
    {

        DEBUG_NONE,
        DEBUG_HIGH,
        DEBUG_MEDIUM,
        DEBUG_LOW,
        DEBUG_NOTE,
        DEBUG_ALL

    };

    void setDebugErrorlevel(debugErrorLevel errorLevel); // not thread safe i guess
    debugErrorLevel getDebugErrorLevel();

} // namespace GLP
