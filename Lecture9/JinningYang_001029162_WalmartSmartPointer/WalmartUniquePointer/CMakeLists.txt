cmake_minimum_required(VERSION 3.17)
project(WalmartUniquePointer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(WalmartUniquePointer
        AbstractItemAPI.cpp
        AbstractItemAPI.h
        AbstractItemFactoryAPI.cpp
        AbstractItemFactoryAPI.h
        AbstractPersonAPI.cpp
        AbstractPersonAPI.h
        AbstractPersonFactoryAPI.cpp
        AbstractPersonFactoryAPI.h
        AbstractStoreAPI.cpp
        AbstractStoreAPI.h
        Item.hpp
        ItemFactory.hpp
        main.cpp
        Person.hpp
        PersonFactory.hpp
        Store.hpp
        Walmart.hpp)
