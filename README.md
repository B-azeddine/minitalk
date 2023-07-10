# minitalk

# Project Overview 💡
The objective of this project is to create two executables: a server and a client. 
The client's role is to transmit information (a string) to the server by utilizing UNIX signals.
The server is responsible for receiving and interpreting this information accurately, subsequently displaying it.
To simplify the compilation process, a Makefile is employed to easily generate the server and client executables.

Behaviour:
- By running the server executable we start up the server and it displays its process id: 
<img width="499" alt="server_start" src="https://github.com/B-azeddine/minitalk/assets/74467756/28033533-2e61-4e50-9afe-854bd0e54d7f">

- By running the client with the process id from the server we can send strings to the server 
<img width="501" alt="client_base" src="https://github.com/B-azeddine/minitalk/assets/74467756/df0de5b4-b740-4943-b0e6-437c40fb011f">

- Server receives bits containing the information, translates them to characters and prints the result as a string: 
<img width="500" alt="server_base" src="https://github.com/B-azeddine/minitalk/assets/74467756/c3a6a78b-f277-4aea-b250-e405e9e07ebf">

