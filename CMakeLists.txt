cmake_minimum_required(VERSION 3.28)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinaryTree myMain.cpp
        BinarySearchTree.h
        QueueList.h
        StackList.h
        Queue.h
        Stack.h
        stackExceptions.h
        queueExceptions.h)