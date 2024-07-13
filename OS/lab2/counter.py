import psutil
import time

def get_free_memory():
    memory_info = psutil.virtual_memory()
    free_memory_mb = memory_info.available / (1024 * 1024)

    return int(free_memory_mb)

def main():
    while True:
        free_memory_mb = get_free_memory()
        with open('log.txt', 'a') as file:
            file.write(f'{time.strftime("%H:%M:%S")}:{free_memory_mb}\n')
        time.sleep(1)


if __name__ == "__main__":
    main()
