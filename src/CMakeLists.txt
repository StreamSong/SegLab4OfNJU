add_executable(main main.cc)

add_subdirectory(CompileAndRun)
add_subdirectory(EquivalanceJudge)
add_subdirectory(User)

target_link_libraries(main
    PRIVATE
        CompileAndRun
        EquivalanceJudge
        User
)