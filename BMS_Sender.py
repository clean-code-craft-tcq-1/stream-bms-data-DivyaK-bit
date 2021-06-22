import Battery_Parameter_Handler

alert_Duration = 10

def startSender():
    Battery_Parameter_Handler.startSender(["Charge_rate" ,"Temperature"],"Console",alert_Duration)

if __name__ == '__main__':
    startSender()