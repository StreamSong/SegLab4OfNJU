add_library(User "")

target_sources(User
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/User.cc
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/User.hh
)