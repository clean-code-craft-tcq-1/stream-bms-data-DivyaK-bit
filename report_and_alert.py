import time

def check_and_alert(parameter_values, battery_parameter,alert_type):
  return (alert_Target_type[alert_type](parameter_values,battery_parameter))  
   
def send_to_console(parameter_values,battery_parameter):
  print(battery_parameter)
  for item in parameter_values:
      print(battery_parameter + str(item))
      time.sleep(0.1)
  return True
  
def send_to_controller(breachType):
  header = 0xfeed
  print(f'{header}, {breachType}')
  return True   

def send_to_email(breachType):
  recepient = "a.b@c.com"
  print(f'To: {recepient}')
  print('Hi, ', breachType)
  return True

alert_Target_type = {'EMAIL': send_to_email, 'CONTROLLER' : send_to_controller, 'CONSOLE' : send_to_console}
