from serial.tools.list_ports import comports

def get_arduino_port():
    #ports = serial.list_ports_comports()
    ports = comports ()
    for port in ports:
        #if "Arduino" in port.description or "CH340" in port.description:
        print (port.device)
        return port.device
    return None

#arduino_port = get_arduino_port()
#if arduino_port:
#    print(arduino_port)
#else:
#    print("No port detected :::")
get_arduino_port()