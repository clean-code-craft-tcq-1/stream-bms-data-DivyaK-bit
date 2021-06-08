import unittest
import Battery_Parameter_Handler

class test_battery_current_ranges(unittest.TestCase):
    
  def test_battery_range(self):    
    self.assertTrue(Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature"],"Console"))    
    
  def test_alertType(self):
    self.assertTrue(Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature", "Soc"],"Console"))
    
  def test_wrong_alertType(self):
    self.assertFalse(Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature", "Soc"],"IPHONE"))
    
  def test_wrong_batteryParam(self):
    self.assertFalse(Battery_Parameter_Handler.process_information(["Volumne" ,"help", "Soc"],"Email"))         
    
  def test_empty_alertType(self):
    self.assertFalse(Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature", "Soc"],""))
    
  def test_empty_batteryParam(self):
    self.assertFalse(Battery_Parameter_Handler.process_information([],"Email"))   
    
if __name__ == '__main__':
  unittest.main()
