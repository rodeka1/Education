import psutil
import datetime
import time

def main():
    while True:
        with open('log.txt', 'a') as f:
            f.write(datetime.datetime.now().strftime('%H:%M:%S')+ ':' + str(len(psutil.pids())) + '\n')
        time.sleep(1)

if __name__ == "__main__":
    main()