# Arduino RS485 with Python Interface
## Overview
This project provides a minimalistic working example of a multi-node [Modbus] (https://en.wikipedia.org/wiki/Modbus) over [RS-485] (https://en.wikipedia.org/wiki/RS-485) measurement network. The sensor nodes are based on [Arduino] (https://www.arduino.cc) with an attached temperature module and RS-485 module. Two examples of a Modbus master is implemented in python script for cyclic data pull from the sensors. Data is logged to terminal prompt for possible copy-paste to excel or text-file.

## Features:
The system is good for projects with long distances between the Arduino and computer due to the robustness of RS-485. 
Several Arduinos can be put on the same RS-485 network (two wires). 
Each Arduino can easily be extended with more sensors and/or functionality. 
The Modbus master is implemented in Python so it is so easy to change and add commands, or have the network as a part of a larger Python-project.

## Hardware
A hardware design has been designed in [Fritzing](http://fritzing.org/), source file and pdf are provided. The hardware modules used are
* Arduino Nano (https://www.arduino.cc/en/Main/arduinoBoardNano)
* RS485 shield (http://www.epanorama.net/newepa/2014/03/21/usb-to-rs485-adapter/)
*	Max 485 module  (https://www.itead.cc/wiki/MAX485_MODULE)
*	DHT sensor (http://www.micropik.com/PDF/dht11.pdf)

## Used libraries
To use this project the libraries listed below are needed. You also need the [Arduino Software] (https://www.arduino.cc/en/Main/Software) and [Python](https://www.python.org).

Arduino
*	The temperature sensor communication requires the DHTLib-library (http://playground.arduino.cc/Main/DHTLib).
*	The Modbus communication requires the ModbusRtu-library (https://github.com/smarmengol/Modbus-Master-Slave-for-Arduino).

Python
*	The python program requires the minimalmodbus-library (https://pypi.python.org/pypi/MinimalModbus).

## Authors
This work was done by Mohammad Al-Jichi during as part of a trainee project at the [Division of Electricity at Uppsala University](http://www.teknik.uu.se/electricity/). The project was supervised by Morgan Rossander.
