from boltiot import Bolt,Sms
import conf,json,time

mybolt = Bolt(conf.API_KEY,conf.DEVICE_ID)
sms = Sms(conf.SID,conf.AUTH_TOKEN,conf.TO_NUMBER,conf.FROM_NUMBER)

while True:
    response = mybolt.serialRead('10')
    data = json.loads(response)
    garbage_value = data['value'].rstrip()
    if(garbage_value == 'Dry Bin is Full!'):
        print(garbage_value)
        resp = sms.send_sms('Smart Garbage Alert: '+str(garbage_value))
        print('Response received from Twilio is: '+str(resp))
        print('Status of SMS at Twilio is: '+str(resp.status))

    time.sleep(30)
