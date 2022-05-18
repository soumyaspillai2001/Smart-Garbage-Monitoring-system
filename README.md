# Smart-Garbage-Monitoring-system
I have created a Smart Garbage Segregation and Monitoring System which is an autonomous system it segregates the waste into 2 categories dry and wet and is collected in separate bins. The Garbage level in bins are monitored and SMS Alert is sent to user once dustbin is full.The alerts continue until user empties the bin. User can empty the bin on time to avoid overflowing of garbage and littering of premises.

Working of the project-

The micro servo motor is set to 90 degree when there is no object on the table. When object is placed infrared sensor detects object is present the waste is placed over soil moisture sensor it detects moisture level and based on dry or wet category the waste is pushed by servo motor into respective bins and servo motor comes back to 90 degree. Infrared sensor is placed at brim of both the bins it checks the level of garbage inside bin. When garbage in bin is full a buzzer rings. Serial data status of bin is sent from Arduino to Bolt wifi module and SMS is sent to user here I have used Twilio SMS API service and boltiot python library. You can create Twilio trial account. Note: Create a conf.py file to store bolt cloud API key, device id, Twilio SID, Auth token, twilio trial phone number and user phone number as string.

Youtube video link of working model - https://youtu.be/fG5cwrMClEA

Visit the project on hackster - https://www.hackster.io/soumyaspillai2001/smart-garbage-segregation-and-monitoring-system-through-sms-41a59c
