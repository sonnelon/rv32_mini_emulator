import subprocess
from sys import argv

bin_file = "./build/mini_riscv_qemu"

def generate_test_file_name(current_test_num):
    ranks = 1
    if 10 < current_test_num < 100: ranks = 2

    test_num = f"00{current_test_num}" if ranks == 1 else f"0{current_test_num}"
    return f"{test_num}_test.dat"

def check_test_result(result, correct, test_id, test_nums): 
    if result != correct:
        log_fail(test_id, test_nums)
        return
    log_success(curr_test_num, test_nums)

def log_success(test_id, test_nums): print(f"{test_id}/{test_nums} TEST PASSED!")
def log_fail(test_id, test_nums): print(f"{test_id}/{test_nums} TEST FAILED!")

def main():
    argc = len(argv)
    if argc < 1 or argc == 0:
        print("argc incorrect value")
        return
    
    test_nums = int(argv[1])
    for i in range(0, test_nums):
        test_id = i+1
        test_name = generate_test_file_name(test_id)
        test_dir = f"./tests/{test_name}"
        try: res = subprocess.run([bin_file, test_dir], capture_output=True, text=True, check=True)
        except: pass
        check_test_result(res.stdout, "", test_id, test_nums) 

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print("\nExited")
