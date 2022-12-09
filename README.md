# pingpong  
un lanceur de 2 programmes sensés communiquer entre eux  

A useful futur project  

Not working atm  

In process :  
Using mkfifo() unstead of pipe()

command "make" will create the pingpong binary + 2 binaries "ping" and "pong" to test the program.  

then command "./script" does exactly the test "./pingpong ping pong"  

Test succeed if terminal output become :  
solver start  
subject start  
ping launched  
pong launched  
(sleep 1 sec)hello  
(sleep 1 sec)coucou  
(sleep 1 sec)hello  
(sleep 1 sec)coucou  
(sleep 1 sec)hello  
(sleep 1 sec)coucou  
(sleep 1 sec)hello  
(sleep 1 sec)coucou  
...  
