# Proxy-Server
A proxy server implemented in C++

Code Explanation: 
    The server decides whether a client's request is valid or not. If it is invalid, error is displayed. Else parsing is being done.
Then it connects to the host server's port and sends it the valid HTTP GET request. Finally it forwards the servers response to the client. 

I have written my own parsing module instead of using the given module. It also does the same thing as the given module, separating the request into individual strings by storing in a buffer, and splitting the buffer string by means of a tokenizer. The reason for using a separate parsing module was the ease of integration with the code.  In case of multiple requests, I have used the fork() function. In order to eliminate errors faced by concurrency, hashing is being used and so that each concurrent request will have a unique id. In case of a https request, message of "BAD REQUEST" Error code 400 is being shown.

The code also checks for errors in various places making it robust. It is well indended and comments are given in necessary places to make it readable. Whenever an anomally occurs like port no is given or if sockfd < 0, then the perror function is being called. These error checks are performed on all necessary conditions.

Design Decisions:
    The project has been designed in a manner such that, even if the user gives an bad query, program doesn't halt,but gives error message. The design of the project takes into account the robustness of the code. To handle concurrent process, we use the fork() funciton which takes care of it. The efficiency of the code is also taken care, like using an efficient hash. Also as an implementation decision, comments are added whenever required so that when a programmer wants to change a module, it can be easily done.






