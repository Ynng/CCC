import requests
import time
import winsound
import time

while True:
  r = requests.get("https://us.vrcover.com/products/facial-interface-foam-replacement-set-for-oculus%E2%84%A2-quest-2-winter-edition")
  t = time.localtime()
  current_time = time.strftime("%H:%M:%S", t)
  if "OutOfStock" in r.text:
    print("Out of stock ", current_time)
  else:
    frequency = 2500  # Set Frequency To 2500 Hertz
    duration = 1000  # Set Duration To 1000 ms == 1 second
    winsound.Beep(frequency, duration)
    print("Have stock\a ", current_time)
  time.sleep(10)