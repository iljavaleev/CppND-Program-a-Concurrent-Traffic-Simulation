#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/ilavaleev/Dev/CppND-Program-a-Concurrent-Traffic-Simulation/build
  make -f /Users/ilavaleev/Dev/CppND-Program-a-Concurrent-Traffic-Simulation/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/ilavaleev/Dev/CppND-Program-a-Concurrent-Traffic-Simulation/build
  make -f /Users/ilavaleev/Dev/CppND-Program-a-Concurrent-Traffic-Simulation/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/ilavaleev/Dev/CppND-Program-a-Concurrent-Traffic-Simulation/build
  make -f /Users/ilavaleev/Dev/CppND-Program-a-Concurrent-Traffic-Simulation/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/ilavaleev/Dev/CppND-Program-a-Concurrent-Traffic-Simulation/build
  make -f /Users/ilavaleev/Dev/CppND-Program-a-Concurrent-Traffic-Simulation/build/CMakeScripts/ReRunCMake.make
fi

