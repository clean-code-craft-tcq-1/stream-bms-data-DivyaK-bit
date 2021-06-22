import random
import json
import report_and_alert

battery_limits = {'TEMPERATURE': [0, 45], 'SOC': [20, 80], 'CHARGE_RATE': [0, 0.8]} 


def generating_random_number(min,max):
    #generate a random int
    if isinstance((min+max) , int):
        return random.randint(min, max)
    #generate a random float
    elif isinstance((min+max) , float):
        return min + (max-min)*random.random()


def process_information(battery_parameters, alert_type):
    check_parameters(battery_parameters)
    check_alert(alert_type)  
    parameter_data = {} 
    for battery_parameter in battery_parameters:
        parameter_data[battery_parameter] = generate_limits(battery_parameter.upper())
    
    json_data = json.dumps(parameter_data)
    publish_data(json_data, alert_type.upper())
    return True

  
def startSender(battery_parameters, alert_type, alert_duration):
    publish_data("START",alert_type.upper())
    while(alert_duration):
        process_information(battery_parameters, alert_type)
        alert_duration = alert_duration - 1;
    publish_data("STOP",alert_type.upper())

def check_parameters(battery_parameters):
  if len(battery_parameters) == 0:
    raise ValueError('Battery parameter is missing')
  for item in battery_parameters:
    if not item.upper() in battery_limits.keys():
      raise KeyError('Battery paramenter is wrong')
    
def check_alert(alert_type): 
  if len(alert_type) == 0:
    raise ValueError('Alert Type is missing')
  elif not alert_type.upper() in report_and_alert.alert_Target_type.keys():
    raise KeyError('Alert Type is Wrong'  )
            
def generate_limits(battery_parameter):
  min, max = battery_limits[battery_parameter]
  return generating_random_number(min, max)
 
def publish_data(parameter_data, alert_type):
  return report_and_alert.check_and_alert(parameter_data ,alert_type)
