#include "ScopedDebug.hpp"
#include "debug.hpp"


namespace GLP
{
    
    ScopedDebug::ScopedDebug(debugErrorLevel errorLevel):
    innerLevel(errorLevel), outerLevel(getDebugErrorLevel())
    {
        setDebugErrorlevel(innerLevel);
    }
    
    ScopedDebug::~ScopedDebug()
    {
        setDebugErrorlevel(outerLevel);
    }
    
} // namespace GLP
