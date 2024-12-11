import os
import json
from http.server import BaseHTTPRequestHandler, HTTPServer

# Set one of the allowed ports (default is 27121)
PORT = 27121

class RequestHandler(BaseHTTPRequestHandler):
    def do_POST(self):
        """Handle POST requests."""
        content_length = int(self.headers['Content-Length'])  # Get the size of data
        post_data = self.rfile.read(content_length)  # Read the data from the request
        
        try:
            # Parse JSON data
            data = json.loads(post_data)
            # print("Received data:", data)
            
            # Extract relevant fields
            problem_name = data['name'].replace(" ", "_").replace(".", "").replace("/", "")[2:]
            problem_group = data['group']
            url = data['url']
            tests = data['tests']

            # Create a folder for the problem
            os.makedirs(problem_name, exist_ok=True)
            os.chdir(problem_name)
            os.makedirs("test_data")
            os.chdir("test_data")

            # Create files for input/output examples
            for i, test in enumerate(tests):
                input_filename = f"test_input_{i + 1}.in"
                output_filename = f"test_output_{i + 1}.out"

                with open(input_filename, "w") as infile:
                    infile.write(test["input"])

                with open(output_filename, "w") as outfile:
                    outfile.write(test["output"])
            
            os.chdir("..")
            os.system("touch main.cpp main.py")

            os.chdir("../Templates")
            # print current directory
            print(os.getcwd())


            with open("PYTHON_TEMPLATE.py", "r") as template:
                with open(f"../{problem_name}/main.py", "w") as main_file:
                    main_file.write(template.read())
            
            with open("CPP_TEMPLATE.cpp", "r") as template:
                with open(f"../{problem_name}/main.cpp", "w") as main_file:
                    main_file.write(template.read())
            os.chdir("..")
            os.chdir(problem_name)
            print(f"Setup complete for problem: {problem_name}")
            self.send_response(200)
            self.end_headers()
            self.wfile.write(b"Problem files created successfully.")
            exit()
        except Exception as e:
            print(f"Error processing request: {e}")
            self.send_response(500)
            self.end_headers()
            self.wfile.write(b"Internal Server Error.")

def run_server():
    """Start the HTTP server."""
    server = HTTPServer(('localhost', PORT), RequestHandler)
    print(f"Server started at http://localhost:{PORT}")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("Server stopped.")
        server.server_close()

if __name__ == "__main__":
    run_server()
