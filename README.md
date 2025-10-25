# Line-Follower-Bot
Line Follower Bot
A Line Follower Bot, as the name suggests follows a drawn line, by using Infrared sensors.

How does it work -
For example, if there are n number of IR sensors, there must me some sensor/sensors (say m) which would give us a different value during any sort of line deflection. Based on m and the side of the sensor(either left or right), we would define the speed and direction of the turn, so that there is close to no/no defelction of line.

PID - Proportional–Integral–Derivative
It is a control algorithm which helps us calculate the speed and direction of the turn of a Line Follower Robot with precision.
It is based on the apporximation of error
The formula for the same goes by - Correction = Kp​×e(t) + Ki​×∫e(t)dt + Kd​×dt/de(t)​

How does it work - 
Let's say n=5, such that we have sensors as sen[5]={1,2,3,4,5}
if sen[0]=1 is deflected, there is a minor deflection and the speed will be calculated according to the formula stated above and the bot takes a right turn.
if both sen[0]=1 and sen[1]=2 get a defelction, its a major one and thus the turn would be sharper, and so on.
 
