cmake_minimum_required(VERSION 3.16)
project(CryptoApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)
find_package(OpenSSL REQUIRED)
find_library(CRYPTOPP_LIB cryptopp) # optional, fallback to find via pkg-config if needed

set(SOURCES
    main.cpp
    gui/MainWindow.cpp
    crypto/AESUtils.cpp
    crypto/BlowfishUtils.cpp
    crypto/RSAUtils.cpp
    crypto/HashUtils.cpp
    core/FileManager.cpp
)
set(HEADERS
    gui/MainWindow.h
    crypto/AESUtils.h
    crypto/BlowfishUtils.h
    crypto/RSAUtils.h
    crypto/HashUtils.h
    core/FileManager.h
)
set(UIS
    gui/MainWindow.ui
)

add_executable(CryptoApp
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

target_include_directories(CryptoApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/gui
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${OPENSSL_INCLUDE_DIR}
)

# link libraries
find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
  pkg_check_modules(CRYPTOPP_PKG cryptopp)
  if(CRYPTOPP_PKG_FOUND)
    target_include_directories(CryptoApp PRIVATE ${CRYPTOPP_PKG_INCLUDE_DIRS})
    target_link_libraries(CryptoApp PRIVATE ${CRYPTOPP_PKG_LIBRARIES})
  else()
    if(CRYPTOPP_LIB)
      target_link_libraries(CryptoApp PRIVATE ${CRYPTOPP_LIB})
    endif()
  endif()
else()
  if(CRYPTOPP_LIB)
    target_link_libraries(CryptoApp PRIVATE ${CRYPTOPP_LIB})
  endif()
endif()

target_link_libraries(CryptoApp PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui OpenSSL::SSL OpenSSL::Crypto)
