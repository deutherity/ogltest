#pragma once
#include "debug.hpp"
// Not thread safe


namespace GLP
{
    class ScopedDebug
    {
    private:
        const debugErrorLevel innerLevel;
        const debugErrorLevel outerLevel;
    public:
        ScopedDebug(debugErrorLevel errorLevel = DEBUG_LOW);
        ~ScopedDebug();
    };
    
} // namespace GLP
