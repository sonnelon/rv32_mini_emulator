cmake_minimum_required(VERSION 3.28)
project(mini_riscv_qemu)
add_executable(mini_riscv_qemu main.c)

target_include_directories(mini_riscv_qemu PRIVATE source/include)

target_sources(mini_riscv_qemu 
    PRIVATE
        source/cli/cli.c
)

target_compile_options(mini_riscv_qemu PRIVATE -Wall -Wpedantic -Wextra)
