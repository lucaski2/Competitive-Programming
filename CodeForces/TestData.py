import os
import subprocess
import filecmp


def run_tests():
  arg = os.getcwd()
  test_input_dir = arg + "/test_data"
  cpp_executable = arg + "/main"
  python_script = arg + "/main.py"
  cpp_file = arg + "/main.cpp"

  # compile cpp file
  
  comp = subprocess.run("g++ -std=c++17 -o " + cpp_executable + " " + cpp_file, shell=True)

  if comp.returncode != 0:
    print("Compilation failed")
    return
  
  inputs = [f for f in os.listdir(test_input_dir) if f.endswith(".in")]
  outputs = [f for f in os.listdir(test_input_dir) if f.endswith(".out")]

  inputs.sort() 
  outputs.sort()

  for i in range(len(inputs)):
    input_file = os.path.join(test_input_dir, inputs[i])
    output_file = os.path.join(test_input_dir, outputs[i])

    # run cpp file, compare, run python file, compare
    cpp_output = subprocess.run(cpp_executable + " < " + input_file, shell=True, capture_output=True)
    python_output = subprocess.run("python3 " + python_script + " < " + input_file, shell=True, capture_output=True)

    # check if cpp_output == output_file or python_output == output_file
    if cpp_output.stdout.decode().strip() == open(output_file, "r").read().strip():
        print("Test case " + str(i) + " passed (cpp)")
        with open(output_file, "r") as f:
            print(f.read())
    elif python_output.stdout.decode().strip() == open(output_file, "r").read().strip():
        print("Test case " + str(i) + " passed (python)")
        with open(output_file, "r") as f:
            print(f.read())
    else:
        print("Test case " + str(i) + " failed")
        print("Expected output:")
        with open(output_file, "r") as f:
            print(f.read())
        if cpp_output.stdout.decode().strip():
            print("Output from cpp:")
            print(cpp_output.stdout.decode(), end='')
        else:
            print("Output from python:")
            print(python_output.stdout.decode(), end="")


run_tests()
