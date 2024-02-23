# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Rafal/Documents/Ulster University Year 4/Object Oriented Programming - EEE507/WarehouseRobot/cmake-build-debug/_deps/olcpge-src"
  "C:/Users/Rafal/Documents/Ulster University Year 4/Object Oriented Programming - EEE507/WarehouseRobot/cmake-build-debug/_deps/olcpge-build"
  "C:/Users/Rafal/Documents/Ulster University Year 4/Object Oriented Programming - EEE507/WarehouseRobot/cmake-build-debug/_deps/olcpge-subbuild/olcpge-populate-prefix"
  "C:/Users/Rafal/Documents/Ulster University Year 4/Object Oriented Programming - EEE507/WarehouseRobot/cmake-build-debug/_deps/olcpge-subbuild/olcpge-populate-prefix/tmp"
  "C:/Users/Rafal/Documents/Ulster University Year 4/Object Oriented Programming - EEE507/WarehouseRobot/cmake-build-debug/_deps/olcpge-subbuild/olcpge-populate-prefix/src/olcpge-populate-stamp"
  "C:/Users/Rafal/Documents/Ulster University Year 4/Object Oriented Programming - EEE507/WarehouseRobot/cmake-build-debug/_deps/olcpge-subbuild/olcpge-populate-prefix/src"
  "C:/Users/Rafal/Documents/Ulster University Year 4/Object Oriented Programming - EEE507/WarehouseRobot/cmake-build-debug/_deps/olcpge-subbuild/olcpge-populate-prefix/src/olcpge-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Rafal/Documents/Ulster University Year 4/Object Oriented Programming - EEE507/WarehouseRobot/cmake-build-debug/_deps/olcpge-subbuild/olcpge-populate-prefix/src/olcpge-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Rafal/Documents/Ulster University Year 4/Object Oriented Programming - EEE507/WarehouseRobot/cmake-build-debug/_deps/olcpge-subbuild/olcpge-populate-prefix/src/olcpge-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
