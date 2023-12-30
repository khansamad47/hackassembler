#add_test(NAME hack_parser COMMAND hack_parser.t)
#add_executable(hack_parser.t hack_parser.t.cpp ../src/hack_parser.cpp ../src/hack_instruction.cpp)
#target_link_libraries(hack_parser.t gtest_main gtest pthread)

#add_test(NAME hack_instruction COMMAND hack_instruction.t)
#add_executable(hack_instruction.t hack_instruction.t.cpp ../src/hack_instruction.cpp)
#target_link_libraries(hack_instruction.t gtest_main gtest pthread)

#add_test(NAME hack_code COMMAND hack_code.t)
#add_executable(hack_code.t hack_code.t.cpp ../src/hack_code.cpp ../src/hack_instruction.cpp)
#target_link_libraries(hack_code.t gtest_main gtest pthread)

include_directories(../src/)