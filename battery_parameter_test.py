import unittest
import Battery_Parameter_Handler

class test_battery_current_ranges(unittest.TestCase):
    
  def test_battery_range(self):    
    self.assertTrue(Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature"],"Console"))
    
  #def test_alertType(self):
   # self.assertTrue(Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature", "Soc"],"Console"))
    
  #def test_wrong_alertType(self):
   # with self.assertRaises(KeyError) as context:
    #    Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature", "Soc"],"PDF")
    #self.assertTrue('Alert Type is Wrong' in str(context.exception))
      
  #def test_wrong_batteryParam(self):
   # with self.assertRaises(KeyError) as context:
    #    Battery_Parameter_Handler.process_information(["Voltage" ,"Temperature", "Soc"],"Email")
    #self.assertTrue('Battery paramenter is wrong' in str(context.exception))         
      
 # def test_empty_alertType(self):
  #  with self.assertRaises(ValueError) as context:
   #     Battery_Parameter_Handler.process_information(["Charge_rate" ,"Temperature", "Soc"],"")
    #self.assertTrue('Alert Type is missing' in str(context.exception))
      
  #def test_empty_batteryParam(self):
   # with self.assertRaises(ValueError) as context:
    #    Battery_Parameter_Handler.process_information([],"Email")
    #self.assertTrue('Battery parameter is missing' in str(context.exception))
    
if __name__ == '__main__':
  unittest.main()
