# tell cmake what our excutable is going to be
add_executable(test test.cpp)

target_link_libraries(test PUBLIC HighFive)
target_link_libraries(test PUBLIC OpenMP::OpenMP_CXX)
target_link_libraries(test PUBLIC Eigen3::Eigen)
install(TARGETS test DESTINATION bin)
