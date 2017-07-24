import getopt, time, sys, serial

def main(argv):
    try:
        opts, args = getopt.getopt(argv,"hf:l:",["f=","l="])
    except getopt.GetoptError:
        print 'fan.py -f <fanstate> -l <lightstate>'
        sys.exit(2)
        
    ser = serial.Serial()
    ser.buadrate = 9600
    ser.port = '/dev/tty.usbmodem1431'
    ser.open()
    
    for opt, arg in opts:
        time.sleep(2)
        if opt == '-h':
            print 'fan.py -f <fanstate> -l <lightstate>'
            sys.exit()
        elif opt in ("-f", "--f"):
            ser.write(('f' + arg).encode())
        elif opt in ("-l", "--l"):
            ser.write('l'.encode())
            
    ser.close()

if __name__ == "__main__":
    main(sys.argv[1:])
