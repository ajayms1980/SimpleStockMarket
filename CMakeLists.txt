# CMake for the feedhandler
PROJECT(StockMarketSample)

cmake_minimum_required( VERSION 2.4 )
cmake_policy(VERSION 2.6.1)


# Setup CPACK info incase we want to package later on
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
SET(COMPLETE_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})
SET(PROJECT_VERSION ${COMPLETE_VERSION})
SET(PROJECT_NAME "simplestockmarket")
#############################################################
# Enable packaging

INCLUDE(InstallRequiredSystemLibraries)

SET(CPACK_PACKAGE_DEFAULT_LOCATION 		"<CMAKE PATH>")
SET(CPACK_INSTALLED_DIRECTORIES 		"<CMAKE DIR PATH>;.")

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY 		"Simple Stock Market")
SET(CPACK_PACKAGE_VENDOR 			"Simple Stock Market")
SET(CPACK_PACKAGE_DESCRIPTION_FILE 		"${CMAKE_CURRENT_SOURCE_DIR}/README")
SET(CPACK_RESOURCE_FILE_LICENSE 		"${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY 		"<CMAKE INSTALL PATH>")
SET(CPACK_INSTALL_PREFIX 			"<CMAKE INSTALL PREFIX>")
SET(CPACK_PACKAGE_EXECUTABLES 			"<CMAKE EXECUTABLE>" "Stock Market Sample")

INCLUDE(CPack)

# Setup the compilation flags
set(DEBUG_CXX_FLAGS   "${COMMON_CXX} ${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
set(RELEASE_CXX_FLAGS "${COMMON_CXX} ${CMAKE_CXX_FLAGS_MINSIZEREL}")

SET ( ARCH ${CMAKE_SYSTEM_PROCESSOR} )
MESSAGE( "******  Machine is : ${ARCH}" )

SET( SIMPLESTOCK "simplestockmarket" )

include_directories( ./include	)

SET( BASE_SRC 
		src/main.cpp
		src/IInstrument.cpp 
		src/InstrumentRatios.cpp
		src/InstrumentRefDataService.cpp 
		src/IRefDataService.cpp 
		src/ITradeService.cpp
		src/ReferenceDataMapping.cpp
		src/StockMarketActivity.cpp
		src/TradeRecord.cpp
		src/TradeService.cpp
   )

# System Specific Libraries

# System Specific Flags
add_definitions( -O3 -Wall -Wno-sign-compare -Wno-unknown-pragmas -DUNIX=1 -D_XOPEN_SOURCE=500 -D_REENTRANT -D_THREAD_SAFE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -DVALGRIND_AWARE=1 -D_DEBUG=1  )


add_executable( ${SIMPLESTOCK} ${BASE_SRC})


