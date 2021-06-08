import random
import report_and_alert

battery_limits = {'TEMPERATURE': [0, 45], 'SOC': [20, 80], 'CHARGE_RATE': [0, 0.8]} 

def generating_random_number(min, max):
  #Generates random numbers between min and max
  if isinstance((min+max) , int):
    return random.randint(min, max)
  elif isinstance((min+max) , float):
    return random.uniform(min, max)    

def process_information(battery_parameters, alert_type):
  check_parameters(battery_parameters)
  check_alert(alert_type)    
  for battery_parameter in battery_parameters:
    parameter_values = generate_limits(battery_parameter.upper())
    publish_data(parameter_values, battery_parameter, alert_type.upper())
  return True

def check_parameters(battery_parameters):
  if len(battery_parameters) == 0:
    return 'Battery parameter is missing'
  for item in battery_parameters:
    if not item.upper() in battery_limits.keys():
      return 'Battery paramenter is wrong'
    
def check_alert(alert_type): 
  if len(alert_type) == 0:
    return 'Alert Type is missing'
  elif not alert_type.upper() in report_and_alert.alert_Target_type.keys():
    return 'Alert Type is Wrong'          
            
def generate_limits(battery_parameter):
  min, max = battery_limits[battery_parameter]
  return generating_random_number(min, max)
 
def publish_data(parameter_values,battery_parameter,alert_type):
  return report_and_alert.check_and_alert(parameter_values, battery_parameter,alert_type)
