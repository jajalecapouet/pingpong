# pingpong  
un lanceur de 2 programmes sensés communiquer entre eux  

A useful futur project  

Not working atm  

In process :  
Using mkfifo() unstead of pipe()

command "make" will create the pingpong binary + 2 binaries "ping" and "pong" to test the program.  

then command "./script" does exactly the test "./pingpong ping pong"  

Test succeed if terminal output become :  
pingpong : ping start  
pingpong : pong start  
pong : Me too !  
ping : I'm alive !  
pong : ping said to me "PING!"   
ping : pong said to me "PONG!"  
pong : ping said to me "PING!"  
ping : pong said to me "PONG!"  
ping : pong said to me "PING!"  
pong : ping said to me "PONG!"  
...  
