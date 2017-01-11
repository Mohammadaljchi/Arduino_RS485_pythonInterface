#This example requires minimalmodbus (https://minimalmodbus.readthedocs.io)

import minimalmodbus
import time

# Initialize the sensor-node, here at com-port:5, slaveId:2
nodeA = minimalmodbus.Instrument('com5', 2) #port name, slave address (in decimal)
precision=0
	
# Print all sensors
a=("time" ,"temperature","humidty")
print(a[0],"\t",a[1],"\t",a[2])
while (1==1):
    temperature = nodeA.read_register(1, precision)# Registernumber, number of decimals
    humidty = nodeA.read_register(2, precision)# Registernumber, number of decimals
    print (time.strftime('%H:%M:%S'),"\t",temperature,"\t",humidty)
    time.sleep(5)#delay for 5 seconds 



