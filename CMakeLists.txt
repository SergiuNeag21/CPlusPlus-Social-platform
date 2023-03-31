cmake_minimum_required(VERSION 3.21)
project(ProiectSDA)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProiectSDA main.cpp Node.h List.h Domain/User.cpp Domain/User.h Tests/Tests.cpp Tests/Tests.h Repository/UsersRepository.cpp Repository/UsersRepository.h UI/UI.cpp UI/UI.h Service/UserService.cpp Service/UserService.h MultiMap.h Domain/Friend.cpp Domain/Friend.h Repository/FriendRepository.cpp Repository/FriendRepository.h Service/FriendService.cpp Service/FriendService.h Domain/Message.cpp Domain/Message.h Repository/MessageRepository.cpp Repository/MessageRepository.h Service/MessageService.cpp Service/MessageService.h Domain/Event.cpp Domain/Event.h Repository/EventRepository.cpp Repository/EventRepository.h Service/EventService.cpp Service/EventService.h)
