import serial
import time
from get_port import get_arduino_port
port = get_arduino_port
arduino_port = port 
baud_rate = 9600
ser = serial.Serial(
    arduino_port, 
    baud_rate, 
    timeout=1
)
time.sleep(2) 
while True:
    data = ser.readline().decode('utf-8').rstrip();
    print(data);