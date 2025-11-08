import subprocess
import os
from sys import argv

BIN_FILE_DIR = "./build/mini_riscv_qemu"
TESTS_DIR = "./tests"

def generate_test_file_names(test_id): return f"{test_id}_test.in", f"{test_id}_test.out"

def check_test_result(result, correct, test_in_dir): 
    if result != correct:
        log_fail(test_in_dir)
        return
    log_success(test_in_dir)

def get_test_out(test_out_dir):
    with open(test_out_dir, "r", encoding="utf-8") as f: return f.read()

def log_success(test_dir): print(f"{test_dir} ... PASSED ✅")
def log_fail(test_dir): print(f"{test_dir} ... FAILED ❌")

def main():
    if not os.path.isfile(BIN_FILE_DIR):
        print(f"ERROR: binary not found at {BIN_FILE_DIR}")
        return

    test_id = 1
    while True:
        test_in_name, test_out_name = generate_test_file_names(test_id)
        test_in_dir = f"{TESTS_DIR}/{test_in_name}"
        test_out_dir = f"{TESTS_DIR}/{test_out_name}"

        if not os.path.isfile(test_in_dir): return

        if not os.path.isfile(test_out_dir):
            print(f"ERROR: {test_in_name} has no .out file")
            return

        try: res = subprocess.run([BIN_FILE_DIR, test_in_dir], capture_output=True, text=True)
        except: pass

        test_id += 1
        check_test_result(res.stdout, get_test_out(test_out_dir), test_in_dir) 

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print("\nExited")
