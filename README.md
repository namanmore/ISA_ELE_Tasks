# ISA_ELE_Tasks  
  
  ## ENTRY TASK  
    For the entry task, I have made an Obstacle Avoiding Car  
    
  ![CAR](https://github.com/namanmore/RM_Taskphase/blob/main/My%20Works/Obstacle%20avoiding1.gif)  
  
   ### Materials Used  
   * Arduino Uno  
   * Jumper Cables  
   * Mini Breadboard  
   * Ultrasonic Sensor  
   * L298n Motor Driver  
   * 2 DC Motors  
   * 2 tyres  
   * 9 V battery
     
   ### Explanation of the materials  
     
   * Arduino Uno is a microcontroller which uses the Atmel 8-bit AVR microcontroller. The board is very useful for beginners as it is equipped with easy to use functions. There are various pins in the board; Digital Pins, Analog in Pins, Power Pins.  
   
   * Jumper Cables are used to help connect pins to the components, in this project I used some Male-Male and Male-Female Jumper Cables. 
   
   * Mini Breadboard helped to connect one pin to multiple components, thereby making the circuit efficient.  
   
   * Ultrasonic Sensor(HC-SR04) is used for determining if an obstacle is present or not. It has 4 pins; Power, Ground, Trig & Echo. Trig Pin is used for emitting Ultrasonic Waves and the Echo Pin is used for determining the time taken for those waves to bounce back and return. The distance can then be calculated mathematically, 
          Distance = Speed * Time / 2 . NOTE: The equation is divided by 2 because the waves travel twice the original distance before coming in contact with the Ultrasonic Sensor.
   
   * Motor Driver is used for controlling the two DC Motors. It has 4 Input , 4 Output and 2 Enable pins. Input pins(2 for each Motor) are connected to Arduino and Output pins(2 for each Motor) are connected to Motors. The speed of the motor can be controlled by using the analogWrite() Function. This is where the Analog pins come into use. The PWM pins on the Arduino are connected with the Enable pins(1 for each motor). The range of the analogWrite() function lies between 0 - 255. NOTE: Instead of connecting the Enable Pins with the PWM pins, they can be connected to Voltage Pins, but then to control the speed of the motors, the Input Pins have to be connected to PWM pins.   
   
  
### Explanation of Project  
The variables uses are: The Ouput Pins of 2 Motors are connected to the respective pins in the Arduino.  
                        The Ultrasonic Sensor's Pins are connected accordingly and hold that respective value.  
                        distance and time variables are used for the calculation of distance of obstacle from the car.  

The Car Moves Forward Until there is an obstacle present, For this I made both the motors move in the same direction forward. When the Car detects an obstacle within the range of 30 cm , the car rotates antiClockwise until there is no obstacle present infront of it. For this motion, I made the Left Motor run in the reverse direction and the Right Motor run in the forward direction, thereby allowing the car to turn antiClockwise.
                        
