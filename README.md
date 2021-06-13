# GPS-Project
GPS Tracking System using ARM Cortex-M4 Based TM4C123G Tiva C Launchpad
## Project Description
This project was developed on a tiva c board. The system first checks for GPS fix and turns a red LED on until it fixes. Once fixed, a green LED is turned on, and the LCD resets, signaling to the user to begin moving. The LCD shows the total distance moved and the speed by which the user is moving. An end point is given to the code. Once the user reaches the end point, a blue LED turns on, a buzzer produces an alarm, and the LCD shows "Arrived", along with the total distance and the average speed of the whole trip.
