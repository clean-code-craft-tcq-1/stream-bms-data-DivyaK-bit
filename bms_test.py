import unittest
import Battery_Parameter_Handler

class test_battery_current_ranges(unittest.TestCase):
    
  def test_battery_range(self):    
    self.assertTrue(Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature"],"Console"))    
    
  def test_alertType(self):
    self.assertTrue(Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature", "Soc"],"Console"))
    
  def test_wrong_alertType(self):
    try:
        Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature", "Soc"],"IPHONE")
    except KeyError:
        print("Alert Type is Wrong")
    
  def test_wrong_batteryParam(self):
    try:
        Battery_Parameter_Handler.process_information(["Volumne" ,"help", "Soc"],"Email")
    except KeyError:
        print("Battery parameter is wrong")
    
  def test_empty_alertType(self):
    try:
        Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature", "Soc"],"")
    except ValueError:
        print("Alert Type is missing")
    
  def test_empty_batteryParam(self):
    try:
        Battery_Parameter_Handler.process_information([],"Email")
    except ValueError:
        print("Battery parameter is missing")
    
if __name__ == '__main__':
  unittest.main()
