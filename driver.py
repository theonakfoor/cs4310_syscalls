import subprocess
import time
import sys

if __name__ == "__main__":

    iterations = 25

    print("")
    print("CS4310 Final Project")
    print("Unix vs. Windows Process Management")
    print("Syscall Comparison (Runtime Analysis)")
    print("")
    print("Comparison Options:")
    print("1: Process Creation (fork & exec / CreateProcessW)")
    print("2: Process Priority (setpriority, nice / SetPriorityClass)")
    print("3: Get current PID (getpid / GetCurrentProcessId)")
    print("4: Yield CPU (sched_yield / SwitchToThread)")
    print("E: Exit benchmark tool")
    print("")

    choice = input("Please select an option to benchmark: ")

    if choice.lower() == "e":
        print("Goodbye!")
        exit(0)

    platform = input("Please select your platform (Unix/Windows): ")

    if platform.strip().lower() == "unix":
        match choice.lower():
            case "1":
                # Process Creation
                binary_path = "binaries/process_creation_unix"
            case "2":
                # Process Priority
                binary_path = "binaries/set_priority_unix"
            case "3":
                # Get current PID
                binary_path = "binaries/get_pid_unix"
            case "4":
                # Yield CPU
                binary_path = "binaries/yield_unix"
            case _:
                print("Invalid menu option selected!")
                exit(0)
    elif platform.strip().lower() == "windows":
        match choice.lower():
            case "1":
                # Process Creation
                pass
            case "2":
                # File I/O
                pass
            case "3":
                # Memory management
                pass
            case "4":
                # Waiting
                pass
            case _:
                print("Invalid menu option selected!")
                exit(0)
    else:
        print("Invalid platform selected!")
        exit(0)

    print("")
    start_ns = time.perf_counter()
    for i in range(iterations):
        result = subprocess.run(
            [binary_path],
            stdout=sys.stdout,
        )
    end_ns = time.perf_counter()
    print("")
    elapsed = end_ns - start_ns

    print("")
    print("Benchmark Results")
    print(f"Total time:\t{elapsed:.6f}s for {iterations} iterations")
    print(f"Average time:\t{(elapsed/iterations):.6f}s per execution")
    print("")
