import time

def check_and_alert(parameter_data, alert_type):
  return (alert_Target_type[alert_type](parameter_data))  
   
def send_to_console(parameter_data):
    print(parameter_data)
    time.sleep(1)
    return True
  
def send_to_controller(breachType):
  header = 0xfeed
  print('{header}, {breachType}')
  return True   

def send_to_email(breachType):
  recepient = "a.b@c.com"
  print('To: {recepient}')
  print('Hi, ', breachType)
  return True

alert_Target_type = {'EMAIL': send_to_email, 'CONTROLLER' : send_to_controller, 'CONSOLE' : send_to_console}
